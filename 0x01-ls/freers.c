#include "header.h"

/**
 * free_file_list - frees file linked list
 * @file_list: file list
 **/
void free_file_list(file_node_t *file_list)
{
	file_node_t *tmp = file_list, *prev;

	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		free(prev->info);
		free(prev->name);
		free(prev->dir_name);
		free(prev);
	}
}
/**
 * free_everything - frees all memory that program is using
 * @d_head: head of dir list
 * @f_head: head of file list
 **/
void free_everything(dir_node_t *d_head, file_node_t *f_head)
{
	file_node_t *f;
	dir_node_t *prev;

	if (f_head)
		free_file_list(f_head);

	while (d_head)
	{
		f = d_head->list;
		free_file_list(f);
		prev = d_head;
		d_head = d_head->next;
		free(prev->dir_name);
		free(prev);
	}
}
