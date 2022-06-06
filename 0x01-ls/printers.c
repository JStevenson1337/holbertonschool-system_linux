#include "header.h"

/**
 * print_list_long - prints file lists in long format (ls -l)
 * @file_list: list to print
 * @flags: ls flags struct (determines printing behavior)
 **/
void print_list_long(file_node_t *file_list, ls_config_t *flags)
{
	char perms[11], time[14], user[256], group[256], name[256], buf[256];
	char sym_link_path[256];
	char *str = "%s %u %s %s %u %s %s";
	unsigned long num_links, size, i;

	if (file_list == NULL)
		return;

	if (flags->reversed)
		while (file_list->next)
			file_list = file_list->next;

	while (file_list != NULL)
	{
		if (PRINT_CHECK(file_list->name) == true)
		{
			get_permissions(perms, file_list->info->st_mode);
			get_time(time, file_list->info->st_mtime);
			get_user(user, file_list->info->st_uid);
			get_group(group, file_list->info->st_gid);
			copy_string(name, file_list->name);
			num_links = file_list->info->st_nlink;
			size = file_list->info->st_size;
			printf(str, perms, num_links, user, group, size, time, name);
			if (S_ISLNK(file_list->info->st_mode) == true)
			{
				for (i = 0; i < 256; i++)
					sym_link_path[i] = '\0';
				sprintf(buf, "%s/%s", file_list->dir_name, file_list->name);
				readlink(buf, sym_link_path, 256);
				printf(" -> %s", sym_link_path);
			}
			putchar('\n');
		}
		file_list = flags->reversed ? file_list->prev : file_list->next;
	}
}
/**
 * print_list - prints lists
 * @file_list: list of files to print
 * @flags: flags
 **/
void print_list(file_node_t *file_list, ls_config_t *flags)
{
	char *delimiter = flags->one_per_line ? "\n" : "  ";
	file_node_t *next;
	bool first_file = true;
	bool rev = flags->reversed && (flags->sort_by_size || flags->sort_by_time);

	if (file_list == NULL)
		return;

	if (rev)
	{
		while (file_list->next)
			file_list = file_list->next;
		next = file_list->prev;
	}
	else
	{
		next = file_list->next;
	}

	while (file_list != NULL)
	{
		next = rev ? file_list->prev : file_list->next;
		if (PRINT_CHECK(file_list->name) == true)
		{
			printf("%s%s", first_file ? "" : delimiter, file_list->name);
			first_file = false;
		}
		file_list = next;
	}
	putchar('\n');
}

/**
 * print_error_message - does what it says, doc
 * @f: f to place on error message
 * Return: error code
 **/
int print_error_message(char *f)
{
	char buffer[256];
	char *error_message;

	if (errno == 13)
		error_message = "hls: cannot open directory %s";
	else
		error_message = "hls: cannot access %s";

	sprintf(buffer, error_message, f);
	perror(buffer);
	return (2);
}

/**
 * print_dirs - print dirs
 * @head: head
 * @flags: flags
 * @printer: printer function
 * Return: status
 **/
int print_dirs(dir_node_t **head, ls_config_t *flags, print_t printer)
{
	dir_node_t *tmp = *head;
	int status = 0;

	if (flags->sort_by_size)
		*head = sort_dir_list_by_size(*head);

	if (flags->reversed)
		while (tmp->next)
			tmp = tmp->next;

	for (; tmp; tmp = flags->reversed ? tmp->prev : tmp->next)
	{
		if (tmp->error_code)
		{
			errno = tmp->error_code;
			status = print_error_message(tmp->dir_name);
		}
		else
		{
			if (flags->recursive)
				recurse_list(head, tmp, flags);
			if (flags->print_dir_name)
				printf("%s:\n", tmp->dir_name);
			if (flags->sort_by_size)
				tmp->list = sort_file_list_by_size(tmp->list);
			if (flags->sort_by_time)
				tmp->list = sort_files_by_time(tmp->list);
			printer(tmp->list, flags);
			if (flags->reversed ? tmp->prev : tmp->next)
				putchar('\n');
		}
	}
	return (status);
}
