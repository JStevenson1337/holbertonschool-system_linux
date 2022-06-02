#include "_getline.h"

/**
 * _getline - reads a line from a file descriptor
 * @fd: file descriptor
 *
 * Return: pointer to line read, or NULL on failure
 */
char *_getline(const int fd)
{
	static readline_t *head = NULL;
	readline_t *curr;
	char *line;
	ssize_t size;

	for (curr = head; curr != NULL; curr = curr->next)
	{
		if (curr->fd == fd)
			break;
	}

	if (curr == NULL)
	{
		curr = malloc(sizeof(readline_t));
		if (curr == NULL)
			return (NULL);
		curr->fd = fd;
		curr->line = NULL;
		curr->size = 0;
		curr->next = head;
		head = curr;
	}
	if (curr->line == NULL)
	{
		curr->line = malloc(READ_SIZE);
		if (curr->line == NULL)
			return (NULL);
		curr->size = READ_SIZE;
	}
	line = curr->line;
	size = read(fd, line, curr->size);
	if (size == -1)
		return (NULL);
	if (size == 0)

		return (NULL);
	line[size] = '\0';
	if (size < curr->size)
		return (line);
	curr->line = realloc(curr->line, size + 1);
	if (curr->line == NULL)
		return (NULL);
	curr->size = size + 1;
	return (another_one(curr));
}

char *another_one(readline_t *curr)
{
	int i, j, size, fd;
	char *line, *tmp;

	for (i = 0; curr[i].next != NULL; i++)
		;
	fd = curr[i].fd;
	line = curr[i].line;
	size = curr[i].size;
	for (j = i; j > 0; j--)
	{
		curr[j].fd = curr[j - 1].fd;
		curr[j].line = curr[j - 1].line;
		curr[j].size = curr[j - 1].size;
	}
	curr[0].fd = fd;
	curr[0].line = line;
	curr[0].size = size;
	tmp = _getline(fd);
	if (tmp == NULL)
		return (NULL);
	curr[0].line = tmp;
	return (tmp);
}

