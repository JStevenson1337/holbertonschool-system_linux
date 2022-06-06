#include "header.h"

/**
 * main - custom ls command
 * @argc: argument count
 * @argv: argument array
 * Return: exit status | 0 on success | 2 on failure
 **/
int main(int argc, char **argv)
{
	int i, status = 0, check = 0, dirs = 0;
	dir_node_t *dirs_list = NULL;
	file_node_t *file_list = NULL;
	DIR *dir_stream;
	ls_config_t flags = {&print_list, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 1; i < argc; i++, status = check ? check : status)
		if (argv[i][0] == '-' && argv[i][1] != '\0')
		{
			if (set_flags(argv[i], &flags))
			{
				free_everything(dirs_list, file_list);
				return (2);
			}
		}
		else
		{
			dir_stream = opendir(argv[i]);
			if (dir_stream == NULL && (errno == ENOTDIR || errno == ENOENT))
				check = add_file_node(argv[i], "", &file_list);
			else
				check = add_dir_node(argv[i], dir_stream, &dirs_list), dirs++;
		}

	if (file_list || dirs > 1 || (file_list == NULL && status != 0))
		flags.print_dir_name = true;
	if (dirs == 0 && file_list == NULL && status == 0)
		add_dir_node(".", opendir("."), &dirs_list);
	flags.printer(file_list, &flags);
	if (dirs && file_list)
		putchar('\n');
	check = print_dirs(&dirs_list, &flags, flags.printer);
	status = check ? check : status;
	free_everything(dirs_list, file_list);
	return (status ? 2 : 0);
}

/**
 * set_flags - sets configurations for ls command
 * @arg: argument
 * @flags: flags struct
 * Return: 0 on success | 2 if invalid option encountered
 **/
int set_flags(char *arg, ls_config_t *flags)
{
	int i;

	for (i = 1; arg[i] != '\0'; i++)
		if (arg[i] == '1')
			flags->one_per_line = true;
		else if (arg[i] == 'a')
			flags->dot = true;
		else if (arg[i] == 'A')
			flags->dot_alt = true;
		else if (arg[i] == 'l')
			flags->printer = &print_list_long;
		else if (arg[i] == 'r')
			flags->reversed = true;
		else if (arg[i] == 'R')
			flags->recursive = true;
		else if (arg[i] == 't')
			flags->sort_by_time = true;
		else if (arg[i] == 'S')
			flags->sort_by_size = true;
		else
		{
			fprintf(stderr, "hls: invalid option -- '%c'\n", arg[i]);
			fprintf(stderr, "Try 'hls --help' for more information.\n");
			return (2);
		}
	return (0);
}
