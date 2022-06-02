#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "_getline.h"

/**
 * main - entry point.
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: always 0.
 */
int main(int ac, char *av[])
{
	char *file = __FILE__;
	int fd;
	char *line;
	int i;

	if (ac > 1)
		file = av[1];
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (EXIT_FAILURE);
	}
	i = 0;
	while ((line = _getline(fd)))
	{
		printf("%s\n", line);
		fflush(stdout);
		i++;
		free(line);
	}
	printf("Total: %d lines\n", i);
	close(fd);
	return (EXIT_SUCCESS);
}
