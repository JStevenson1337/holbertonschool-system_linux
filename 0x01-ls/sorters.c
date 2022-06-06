#include "header.h"

/**
 * sort_files_by_time - sort file nodes by time of most recent modification
 * @head: head
 * Return: head
 **/
file_node_t *sort_files_by_time(file_node_t *head)
{
	file_node_t *this = head;

	if (!head || !head->next)
		return (head);

	while (this->next)
	{
		if (compare_files_by_time(this, this->next))
		{
			if (this == head)
				head = this->next;
			swap_files(this, this->next);
		}
		else
			this = this->next;
	}

	for (this = head; this->next; this = this->next)
		if (compare_files_by_time(this, this->next))
			return (sort_files_by_time(head));

	return (head);
}

/**
 * swap_files - swap two file nodes
 * @a: file node 1
 * @b: file node 2
 **/
void swap_files(file_node_t *a, file_node_t *b)
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

/**
 * compare_files_by_time - compare file nodes by time of most recent mod
 * @a: file node 1
 * @b: file node 2
 * Return: 1 if a | 0 if b
 **/
int compare_files_by_time(file_node_t *a, file_node_t *b)
{
	time_t a_time = a->info->st_mtime;
	time_t b_time = b->info->st_mtime;
	time_t a_nano = a->info->st_mtim.tv_nsec;
	time_t b_nano = b->info->st_mtim.tv_nsec;

	if (a_time == b_time && a_nano == b_nano)
		return (which_goes_first(a->name, b->name) != a->name);

	return (a_time < b_time || (a_time == b_time && a_nano < b_nano));
}

/**
 * sort_file_list_by_size - sorst a file_node_t linked list by size
 * @head: head of linked list
 * Return: pointer to head
 **/
file_node_t *sort_file_list_by_size(file_node_t *head)
{
	file_node_t *this, *that, *tmp;
	size_t a, b;
	char *c, *d;

	if (!head || !head->next)
		return (head);

	for (this = head, that = head->next; that; that = that->next)
	{
		a = this->info->st_size, b = that->info->st_size;
		c = this->name, d = that->name;
		if (a > b || (a == b && which_goes_first(c, d) == c))
		{
			if (this->next != that)
			{
				if (this->prev)
					this->prev->next = this->next;
				else
					head = this->next;
				this->next->prev = this->prev, this->next = that;
				this->prev = that->prev, that->prev->next = this;
				that->prev = this;
			}
			this = that;
		}
		else if ((!that->next && (a < b || which_goes_first(c, d) == d)))
		{
			if (this->prev)
				this->prev->next = this->next;
			else
				head = this->next;
			this->next->prev = this->prev, tmp = this->next, this->next = NULL;
			this->prev = that, that->next = this, this = tmp, that = this;
		}
	}

	return (confirm_sorted_by_size(head));
}

/**
 * confirm_sorted_by_size - helper function for sort_file_list_by_size
 * @head: head of list
 * Return: pointer to head of list
 **/
file_node_t *confirm_sorted_by_size(file_node_t *head)
{
	file_node_t *tmp;

	for (tmp = head; tmp->next; tmp = tmp->next)
	{
		if (tmp->info->st_size > tmp->next->info->st_size)
			continue;
		if (tmp->info->st_size < tmp->next->info->st_size)
			return (sort_file_list_by_size(head));
		if (which_goes_first(tmp->name, tmp->next->name) != tmp->name)
			return (sort_file_list_by_size(head));
	}

	return (head);
}
