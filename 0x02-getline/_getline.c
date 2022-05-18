#include "_getline.h"

/**
 * _getline - reads a line from a file descriptor
 * @fd: file descriptor
 * Return: pointer to line read
 */
char *_getline(const int fd)
{
	static reader_t *readers;
	reader_t *rd;
	char *bytes;
	int bytes_read;

	if (fd < 0)
		return (NULL);

	/* Find the reader for this file descriptor */
	rd = readers;
	while (rd != NULL && rd->fd != fd)
		rd = rd->next;

	/* If the reader doesn't exist, create it */
	if (rd == NULL)
	{
		rd = malloc(sizeof(reader_t));
		if (rd == NULL)
			return (NULL);
		rd->fd = fd;
		rd->buf = malloc(READ_SIZE);
		if (rd->buf == NULL)
		{
			free(rd);
			return (NULL);
		}
		rd->bytes = 0;
		rd->next = readers;
		readers = rd;
	}

	/* Read bytes from the file descriptor */
	bytes_read = read(fd, rd->buf + rd->bytes, READ_SIZE - rd->bytes);
	if (bytes_read < 0)
		return (NULL);
	rd->bytes += bytes_read;

	/* Find the newline */
	bytes = memchr(rd->buf, '\n', rd->bytes);
	if (bytes == NULL)
		return (NULL);

	/* Copy the line to a new buffer and return it */
	bytes = strndup(rd->buf, bytes - rd->buf);
	if (bytes == NULL)
		return (NULL);
	rd->bytes -= bytes - rd->buf;
	memmove(rd->buf, bytes, rd->bytes);
	return (bytes);
}
