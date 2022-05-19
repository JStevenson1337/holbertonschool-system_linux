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
	readline_t *curr = head;
	char *line = NULL;
	ssize_t read_bytes;

	if (fd < 0)
		return (NULL);

	while (1)
	{
		if (curr == NULL)
		{
			curr = malloc(sizeof(readline_t));
			if (curr == NULL)
				return (NULL);
			curr->line = NULL;
			curr->len = 0;
			curr->size = 0;
			curr->next = NULL;
			if (head == NULL)
				head = curr;
			else
			{
				readline_t *tmp = head;
				while (tmp->next != NULL)
					tmp = tmp->next;
				tmp->next = curr;
			}
		}
		if (curr->line == NULL)
		{
			curr->line = malloc(sizeof(char) * READ_SIZE);
			if (curr->line == NULL)
				return (NULL);
			curr->size = READ_SIZE;
		}
		if (curr->len == curr->size)
		{
			curr->line = realloc(curr->line, curr->size * 2);
			if (curr->line == NULL)
				return (NULL);
			curr->size *= 2;
		}
		read_bytes = read(fd, curr->line + curr->len, 1);
		if (read_bytes == -1)
			return (NULL);
		if (read_bytes == 0)
		{
			if (curr->len == 0)
				return (NULL);
			line = curr->line;
			curr->line = NULL;
			curr->len = 0;
			curr->size = 0;
			return (line);
		}
		if (curr->line[curr->len] == '\n')
		{
			line = curr->line;
			curr->line = NULL;
			curr->len = 0;
			curr->size = 0;
			return (line);
		}
		curr->len++;
	}
}


