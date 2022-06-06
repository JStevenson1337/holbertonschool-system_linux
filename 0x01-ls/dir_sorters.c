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
 * compare_dirs_by_size - compare two dirs by size
 * @a: directory node 1
 * @b: directory node 2
 * Return: 1 if a is smaller | 0 if b is larger
 **/
int compare_dirs_by_size(dir_node_t *a, dir_node_t *b)
{
	struct stat info;

	if (a->size == -1)
	{
		lstat(a->dir_name, &info);
		a->size = info.st_size;
	}
	if (b->size == -1)
	{
		lstat(b->dir_name, &info);
		b->size = info.st_size;
	}

	if (a->size == b->size)
		return (which_goes_first(a->dir_name, b->dir_name) != a->dir_name);

	return (a->size < b->size);
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
