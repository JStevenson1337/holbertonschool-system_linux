#include "_getline.h"

/**
 * char *getline - entry point
 * @fd: file descriptor
 * Return: pointer to line or NULL
 */
char *_getline(const int fd)
{
	static getline_t *getlines;
	getline_t *ptr;
	char *bytes;
	int bytes_read;

	if (fd == -1)
	{
		for (ptr = getlines; ptr; ptr = getlines)
		{
			getlines = ptr->next;
			free(ptr->buf);
			free(ptr);
		}
		return (NULL);
	}

	for (ptr = getlines; ptr; ptr = ptr->next)
		if (ptr->fd == fd)
		{
			if (ptr->bytes <= 0)
				ptr->bytes = read(fd, ptr->buf, READ_SIZE);
			return (find_line(ptr));
		}

	bytes = malloc(sizeof(char) * READ_SIZE);
	bytes_read = read(fd, bytes, READ_SIZE);
	if (bytes_read <= 0)
	{
		free(bytes);
		return (NULL);
	}
	ptr = malloc(sizeof(getline_t));
	if (ptr == NULL)
		return (NULL);
	ptr->fd = fd;
	ptr->buf = bytes;
	ptr->bytes = bytes_read;
	ptr->next = getlines;
	getlines = ptr;
	return (find_line(ptr));
}

/**
 * find_line - entry point.
 * @ptr: pointer to getline_t
 * Return: pointer to line
 */
char *find_line(getline_t *ptr)
{
	int i, j, line_size = 0, bytes_copied = 0;
	char *line = NULL, *tmp;

	while (ptr->bytes > 0)
	{
		if (line_size < bytes_copied + ptr->bytes + 1)
		{
			line_size += ptr->bytes + 1, tmp = malloc(sizeof(char) * line_size);
			if (tmp == NULL)
			{
				free(line);
				return (NULL);
			}
			memcpy(tmp, line, bytes_copied);
			memset(tmp + bytes_copied, 
			//TODO rewrite memset and memcopy to use pointers

			'\0', line_size - bytes_copied);
			free(line), line = tmp;
		}

		for (i = 0; i < ptr->bytes; i++)
			if (ptr->buf[i] == '\n')
			{
				ptr->buf[i++] = '\0', ptr->bytes -= i;
				memcpy(line + bytes_copied, ptr->buf, i);
				for (j = 0; i < READ_SIZE; j++, i++)
					ptr->buf[j] = ptr->buf[i];
				for (; j < READ_SIZE; j++)
					ptr->buf[j] = '\0';
				return (line);
			}

		memcpy(line + bytes_copied, ptr->buf, ptr->bytes);
		bytes_copied += ptr->bytes;
		ptr->bytes = read(ptr->fd, ptr->buf, READ_SIZE);
	}

	return (line);
}


