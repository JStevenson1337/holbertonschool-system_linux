#include "header.h"

/**
 * add_dir_node - add a directory node to a dir_node_t linked list
 * @dir_name: directory name
 * @stream: directory stream
 * @head: head of dir_node_t list where new node will be added
 * Return: 0 on success | an error code on failure
 **/
int add_dir_node(char *dir_name, DIR *stream, dir_node_t **head)
{
	dir_node_t *new_node, *tmp;
	struct dirent *read;
	file_node_t *file_head = NULL;
	int error_code = errno;

	new_node = malloc(sizeof(dir_node_t));
	new_node->dir_name = duplicate_string(dir_name);
	new_node->next = NULL, new_node->prev = NULL;
	new_node->size = -1, new_node->error_code = stream ? 0 : error_code;
	if (new_node->error_code == 0)
	{
		while ((read = readdir(stream)) != NULL)
			error_code = add_file_node(read->d_name, dir_name, &file_head);
		closedir(stream);
	}
	new_node->list = file_head;
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node->error_code);
	}
	tmp = *head;
	while (tmp && which_goes_first(dir_name, tmp->dir_name) != dir_name)
		new_node->prev = tmp, tmp = tmp->next;
	if (tmp)
	{
		new_node->prev = tmp->prev;
		if (tmp->prev)
			tmp->prev->next = new_node;
		new_node->next = tmp, tmp->prev = new_node;
		if (tmp == *head)
			*head = new_node;
	}
	else
		new_node->prev->next = new_node;
	return (new_node->error_code);
}

/**
 * add_file_node - add a file node to a file_node_t linked list
 * @file_name: file name
 * @dir_name: dir name
 * @head: head of file_node_t list where new node will be added
 * Return: 0 on success | an error code if lstat fails
 **/
int add_file_node(char *file_name, char *dir_name, file_node_t **head)
{
	file_node_t *new_node, *tmp;
	struct stat *info = malloc(sizeof(struct stat));
	char file_path[512];
	int i, j;

	for (i = 0; dir_name[i]; i++)
		file_path[i] = dir_name[i];
	if (i)
		file_path[i++] = '/';
	for (j = 0; file_name[j]; i++, j++)
		file_path[i] = file_name[j];
	file_path[i] = '\0';
	if (lstat(file_path, info) == -1)
	{
		free(info);
		return (print_error_message(file_name));
	}
	new_node = file_node_init(file_name, dir_name, info);
	if (*head == NULL)
	{
		*head = new_node;
		return (0);
	}
	tmp = *head;
	while (tmp && which_goes_first(file_name, tmp->name) != file_name)
		new_node->prev = tmp, tmp = tmp->next;
	if (tmp)
	{
		new_node->prev = tmp->prev;
		if (tmp->prev)
			tmp->prev->next = new_node;
		new_node->next = tmp;
		tmp->prev = new_node;
		if (tmp == *head)
			*head = new_node;
	}
	else
		new_node->prev->next = new_node;
	return (0);
}

/**
 * file_node_init - init file node
 * @name: name
 * @dir_name: dir name
 * @info: info
 * Return: pointer to node
 **/
file_node_t *file_node_init(char *name, char *dir_name, struct stat *info)
{
	file_node_t *new_node;

	new_node = malloc(sizeof(file_node_t));
	new_node->name = duplicate_string(name);
	new_node->dir_name = duplicate_string(dir_name);
	new_node->info = info;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

/**
 * recurse_list - list directory recursively
 * @head: head of list
 * @dir: directory of interest
 * @flags: options inputted into program
 **/
void recurse_list(dir_node_t **head, dir_node_t *dir, ls_config_t *flags)
{
	dir_node_t *oth, *alt;

	if (flags->reversed)
	{
		oth = dir->prev, dir->prev = add_subdirs(dir, flags);
		if (dir->prev)
		{
			flags->print_dir_name = true, dir->prev->next = dir;
			for (alt = dir->prev; alt->prev; alt = alt->prev)
				;
			alt->prev = oth;
			if (oth)
				oth->next = alt;
			else
				*head = alt;
		}
		else
		{
			dir->prev = oth;
		}
	}
	else
	{
		oth = dir->next, dir->next = add_subdirs(dir, flags);
		if (dir->next)
		{
			flags->print_dir_name = true, dir->next->prev = dir;
			for (alt = dir->next; alt->next; alt = alt->next)
				;
			alt->next = oth;
			if (oth)
				oth->prev = alt;
		}
		else
		{
			dir->next = oth;
		}
	}
}

/**
 * add_subdirs - include a directory's subdirectories in directory list
 * @dir: directory node
 * @flags: flags (options) passed onto program
 * Return: pointer to node
 **/
dir_node_t *add_subdirs(dir_node_t *dir, ls_config_t *flags)
{
	file_node_t *tmp = dir->list;
	dir_node_t *new = NULL, *prev = NULL;
	char path[512];

	if (flags->reversed)
		while (tmp->next)
			tmp = tmp->next;

	for (; tmp; tmp = flags->reversed ? tmp->prev : tmp->next)
		if (approve_open_dir(tmp, flags))
		{
			sprintf(path, "%s/%s", dir->dir_name, tmp->name);
			add_dir_node(path, opendir(path), &new);
			if (flags->reversed)
			{
				new->next = prev;
				if (prev)
					prev->prev = new;
			}
			else
			{
				new->prev = prev;
				if (prev)
					prev->next = new;
			}
			prev = new, new = NULL;
		}

	if (flags->reversed && prev)
		while (prev->next)
			prev = prev->next;
	else if (prev)
		while (prev->prev)
			prev = prev->prev;

	if (flags->sort_by_size)
		prev = sort_dir_list_by_size(prev);

	return (prev);
}
