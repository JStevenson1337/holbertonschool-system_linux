#include "_getline.h"

/**
<<<<<<< HEAD
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
=======
 * free_static_var - entry point.
 * @all_text_read_fd: All lines for all fds
 * @all_fds: All fds
 * @all_buff_fd: All buffer for all fds
 * @num_fds: Numbers of fds
 * Return: always -1.
 */
char *free_static_var(char ***all_text_read_fd, int ***all_fds,
	char ***all_buff_fd, int *num_fds)
{
	int index = 0;

	if (!(*all_text_read_fd) && !(*all_fds) && !(*all_buff_fd) && !(*num_fds))
		return (NULL);
	for (index = 0; index < *num_fds; index++)
	{
		free((*all_fds)[index]);
		(*all_fds)[index] = NULL;
		free((*all_buff_fd)[index]);
		(*all_buff_fd)[index] = NULL;
	}
	free(*all_text_read_fd);
	*all_text_read_fd = NULL;
	free(*all_fds);
	*all_fds = NULL;
	free(*all_buff_fd);
	*all_buff_fd = NULL;

	*num_fds = 0;
	return (NULL);
}

/**
 * realloc_all_text_fd - entry point.
 * @all_text_fd: All lines for all fds
 * @all_fds: All fds
 * @all_buff_fd: All buffer for all fds
 * @num_fds: Numbers of fds
 * @num_fds_plus: Numbers of fds plus one
 * Return: 1 on success otherwise 0.
 */
int realloc_all_text_fd(char ***all_text_fd, int ***all_fds,
	char ***all_buff_fd, int num_fds, int num_fds_plus)
{
	int index = 0;
	int **new_all_fds = NULL;
	char **new_all_text_fd = NULL, **new_all_buf_fd;

	new_all_fds = malloc(sizeof(int *) * num_fds_plus);
	if (!new_all_fds)
		return (0);
	for (index = 0; index < num_fds; index++)
		new_all_fds[index] = (*all_fds)[index];
	new_all_fds[index] = NULL;

	new_all_text_fd = malloc(sizeof(char *) * num_fds_plus);
	if (!new_all_text_fd)
	{
		free(new_all_fds);
		return (0);
	}
	for (index = 0; index < num_fds; index++)
		new_all_text_fd[index] = (*all_text_fd)[index];
	new_all_text_fd[index] = NULL;

	new_all_buf_fd = malloc(sizeof(char *) * num_fds_plus);
	if (!new_all_text_fd)
	{
		free(new_all_fds);
		free(new_all_text_fd);
		return (0);
	}
	for (index = 0; index < num_fds; index++)
		new_all_buf_fd[index] = (*all_buff_fd)[index];
	new_all_buf_fd[index] = NULL;

	free(*all_fds);
	(*all_fds) = new_all_fds;
	free(*all_text_fd);
	(*all_text_fd) = new_all_text_fd;
	free(*all_buff_fd);
	(*all_buff_fd) = new_all_buf_fd;

	return (1);
}

/**
 * num_fds_realloc - entry point.
 * @all_text_fd: All lines for all fds
 * @all_fds: All fds
 * @all_buff_fd: All buffer for all fds
 * @num_fds: Numbers of fds
 * @fd: Fd id
 * Return: a positive number on sucess always -1.
 */
int num_fds_realloc(char ***all_text_fd, int ***all_fds, char ***all_buff_fd,
	int *num_fds, int fd)
{
	int *new_fd_num = NULL;

	if (!(*num_fds))
	{
		(*all_text_fd) = malloc(sizeof(char *) * 1);
		if (!(*all_text_fd))
			return (-1);
		(*all_fds) = malloc(sizeof(int *) * 1);
		if (!(*all_fds))
		{
			free(*all_text_fd);
			*all_text_fd = NULL;
			return (-1);
		}
		(*all_buff_fd) = malloc(sizeof(char *) * 1);
		if (!(*all_buff_fd))
		{
			free(*all_text_fd);
			*all_text_fd = NULL;
			free(*all_fds);
			*all_fds = NULL;
			return (-1);
		}
		(*all_text_fd)[0] = NULL;
		(*all_fds)[0] = NULL;
		(*all_buff_fd)[0] = NULL;
	}
	else if (!realloc_all_text_fd(all_text_fd, all_fds, all_buff_fd, *num_fds,
		*num_fds + 1))
		return (-1);
	new_fd_num = malloc(sizeof(int) * 3);
	if (!new_fd_num)
		return (-1);
	new_fd_num[0] = fd;
	new_fd_num[1] = 0;
	new_fd_num[2] = 0;
	(*all_fds)[*num_fds] = new_fd_num;
	(*num_fds) = (*num_fds) + 1;
	return (*num_fds - 1);
}

/**
 * set_new_line - entry point.
 * @all_text_fd: All lines for all fds
 * @all_fds: All fds
 * @all_buff_fd: All buffer for all fds
 * @fd_pos: Position in the array of the fd
 * @b: current buffer of the read fucntion
 * @l_jum: last potision + 1 of the new line char
 * @i_buff: position of the new line char
 * @r: Number of characters read
 * Return: always 0.
 */
int set_new_line(char **all_text_fd, int **all_fds, char **all_buff_fd,
	int fd_pos, char *b, int l_jum, int i_buff, int r)
{
	char *new_mes = NULL;
	int len_message = 0;

	if (all_text_fd[fd_pos])
		for (len_message = 0; all_text_fd[fd_pos][len_message] != '\0';
			len_message++)
			continue;
	new_mes = malloc(sizeof(char) * (len_message + i_buff - l_jum + 1));
	if (!new_mes)
		return (1);
	if (all_text_fd[fd_pos])
		strcpy(new_mes, all_text_fd[fd_pos]);
	strncpy(&(new_mes[len_message]), &(b[l_jum]), (i_buff - l_jum));
	new_mes[len_message + i_buff - l_jum] = '\0';
	if (all_text_fd[fd_pos])
		free(all_text_fd[fd_pos]);
	all_text_fd[fd_pos] = new_mes;
	if (i_buff + 1 >= r)
	{
		if (all_buff_fd[fd_pos])
		{
			free(all_buff_fd[fd_pos]);
			all_buff_fd[fd_pos] = NULL;
		}
		return (0);
	}
	all_buff_fd[fd_pos] = b;
	all_fds[fd_pos][2] = r;
	all_fds[fd_pos][1] = i_buff + 1;
	return (0);
}

/**
 * set_new_line - entry point.
 * @all_text_fd: All lines for all fds
 * @all_fds: All fds
 * @all_buff_fd: All buffer for all fds
 * @fd_pos: Position in the array of the fd
 * @b: buffer
 * @start: index where start the line
 * @stop: total of char of the buffer
 * Return: always 0.
 */
int read_buffer(char **all_text_fd, int **all_fds, char **all_buff_fd,
	int fd_pos, char *b, int start, int stop)
{
	int i_buff = 0;

	for (i_buff = start; i_buff < stop; i_buff++)
	{
		if (b[i_buff] == '\n')
		{
			set_new_line(all_text_fd, all_fds, all_buff_fd, fd_pos, b,
				start, i_buff, stop);
			return (1);
		}
	}
	set_new_line(all_text_fd, all_fds, all_buff_fd, fd_pos, b, start,
		i_buff, stop);
	if (i_buff == stop && start < stop && stop != READ_SIZE)
		return (1);
	return (0);
}

/**
 * _getline - entry point.
 * @fd: file descriptor id
 * Return: a string pointer on succes otherwise NULL.
 */
char *_getline(const int fd)
{
	char *b = NULL;
	int r = 0;
	int i_buff = 0;
	int fd_pos = 0;
	int *new_fd_num = NULL;
	char **all_text_fd = NULL;
	int **all_fds = NULL;
	char **all_buff_fd = NULL;
	int num_fds = 0;

	if (fd < 0)
		return (NULL);
	fd_pos = get_fd_pos(&all_text_fd, &all_fds, &all_buff_fd, &num_fds, fd);
	if (fd_pos == -1)
		return (NULL);
	if (all_buff_fd[fd_pos])
	{
		b = all_buff_fd[fd_pos];
		i_buff = all_fds[fd_pos][1];
		r = all_fds[fd_pos][2];
	}
	else
	{
		b = malloc(sizeof(char) * READ_SIZE);
		if (!b)
			return (NULL);
		r = read(fd, b, READ_SIZE);
		if (r < 0)
		{
			free(b);
			return (NULL);
		}
		all_buff_fd[fd_pos] = b;
		all_fds[fd_pos][2] = r;
		all_fds[fd_pos][1] = 0;
		i_buff = 0;
	}
	if (read_buffer(all_text_fd, all_fds, all_buff_fd, fd_pos, b, i_buff, r))
	{
		new_fd_num = malloc(sizeof(int) * 3);
		if (!new_fd_num)
			return (NULL);
		new_fd_num[0] = fd;
		new_fd_num[1] = 0;
		new_fd_num[2] = 0;
		all_fds[fd_pos] = new_fd_num;
		all_buff_fd[fd_pos] = NULL;
		all_text_fd[fd_pos] = NULL;

		return (NULL);
	}
	return (all_text_fd[fd_pos]);
}

/**
 * get_fd_pos - entry point.
 * @all_text_fd: All lines for all fds
 * @all_fds: All fds
 * @all_buff_fd: All buffer for all fds
 * @num_fds: Number of fds
 * @fd: file descriptor id
 * Return: position in the array of the fd
 */
int get_fd_pos(char ***all_text_fd, int ***all_fds, char ***all_buff_fd, int *num_fds, int fd)
{
	int i = 0;
	int fd_pos = -1;

	if (!*all_text_fd)
	{
		*all_text_fd = malloc(sizeof(char *) * 1);
		if (!*all_text_fd)
			return (-1);
		*all_text_fd[0] = NULL;
		*all_fds = malloc(sizeof(int *) * 1);
		if (!*all_fds)
			return (-1);
		*all_fds[0] = NULL;
		*all_buff_fd = malloc(sizeof(char *) * 1);
		if (!*all_buff_fd)
			return (-1);
		*all_buff_fd[0] = NULL;
		*num_fds = 0;
	}
	for (i = 0; i < *num_fds; i++)
	{
		if ((*all_fds)[i][0] == fd)
		{
			fd_pos = i;
			break;
>>>>>>> parent of 7ac1bf0 (revert)
		}
		return (NULL);
	}
<<<<<<< HEAD

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
			memset(tmp + bytes_copied, '\0', line_size - bytes_copied);
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
=======
	if (fd_pos == -1)
	{
		*all_text_fd = realloc(*all_text_fd, sizeof(char *) * (*num_fds + 1));
		if (!*all_text_fd)
			return (-1);
		*all_text_fd[*num_fds] = NULL;
		*all_fds = realloc(*all_fds, sizeof(int *) * (*num_fds + 1));
		if (!*all_fds)
			return (-1);
		*all_fds[*num_fds] = NULL;
		*all_buff_fd = realloc(*all_buff_fd, sizeof(char *) * (*num_fds + 1));
		if (!*all_buff_fd)
			return (-1);
		*all_buff_fd[*num_fds] = NULL;
		fd_pos = *num_fds;
		(*num_fds)++;
	}
	return (fd_pos);
>>>>>>> parent of 7ac1bf0 (revert)
}


