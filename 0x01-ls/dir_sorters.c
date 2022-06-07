#include "header.h"

/**
 * sort_dir_list_by_size - sorts a directory list by size
 * @head: head of list
 * Return: head
 **/
dir_node_t *sort_dir_list_by_size(dir_node_t *head)
{
	dir_node_t *this = head;

	if (!this)
		return (this);

	while (this->next)
		if (compare_dirs_by_size(this, this->next))
		{
			if (this == head)
				head = this->next;
			swap_dirs(this, this->next);
		}
		else
			this = this->next;

	for (this = head; this->next; this = this->next)
		if (compare_dirs_by_size(this, this->next))
			return (sort_dir_list_by_size(head));

	return (head);
}


/**
 * compare_dirs_by_size - compares two directory nodes by size
 * @a: directory node 1
 * @b: directory node 2
 * Return: 1 if a > b | 0 if a < b
 **/
int compare_dirs_by_size(dir_node_t *a, dir_node_t *b)
{
	if (a->info->st_size > b->info->st_size)
		return (1);
	else if (a->info->st_size < b->info->st_size)
		return (0);
	else
		return (compare_dirs_by_name(a, b));
}


/**
 * swap_dirs - swap position of two directory nodes
 * @a: first node
 * @b: second node
 **/
void swap_dirs(dir_node_t *a, dir_node_t *b)
{
	if (a->prev)
		a->prev->next = b;
	b->prev = a->prev;
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	b->next = a;
	a->prev = b;
}
