#include "hls.h"
/**
 * listFiles - list files in a directory
 * @dirname: directory name
 *
 * Return: void
 */
void listFiles(char* dirname)
{
	DIR *dir;
	struct dirent *entry;
	file_t *file;

	if (!(dir = opendir(dirname)))
		print_error_exit("hls: cannot open directory: ");
	while ((entry = readdir(dir)))
	{
		if (entry->d_name[0] != '.')
		{
			file = malloc(sizeof(BUF_SIZE));
			if (!file)
				print_error_exit("hls: malloc error: ");
			file->name = entry->d_name;
			file->statbuf = malloc(sizeof(struct stat));
			if (!file->statbuf)
				print_error_exit("hls: malloc error: ");
			if (stat(entry->d_name, file->statbuf) == -1)
				print_error_exit("hls: cannot access: ");
			if (S_ISDIR(file->statbuf->st_mode))
				listFiles(entry->d_name);
			else
				printFile(file);
		}
	}
	closedir(dir);
}


/**
 * main - main function
 * @argc: Number of arguments
 * @argv: argv Array of arguments
 * @return 0 if success, -1 otherwise
 */
int main(int argc, char **argv)
{
	char *dirname = "cd";
	int flags = 0;
	int i = 0;

	if (argc > 1)
	{
		dirname = argv[1];
		i = 2;
	}
	if (argc > 2)
	{
		flags = parse_flags(&i);
	}
	if (flags == -1)
	{
		print_error_exit("hls: invalid option -- '%c'\n");
	}
	listFiles(dirname);
	return (0);
}

int parse_flags(int *flags)
{
	int i = 0;
	int ret = 0;
	char *flags_str = "1lRartu";

	while (flags_str[i] != '\0')
	{
		if (*flags == flags_str[i])
		{
			ret = flags_str[i];
			break;
		}
		i++;
	}
	return (ret);
}
