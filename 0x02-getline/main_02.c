#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "_getline.h"

/**
 * init_fds - Open files
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: Set of FDs
 */
int *init_fds(int ac, char *av[])
{
	int nb_files = 1;
	int *fds;
	int i;

	if (ac > 2)
		nb_files = atoi(av[1]);
	fds = malloc((nb_files + 1) * sizeof(int));
	fds[nb_files] = -1;
	if (ac <= 2)
	{
		fds[0] = open(__FILE__, O_RDONLY);
		if (fds[0] == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		for (i = 0; i < nb_files; i++)
		{
			fds[i] = open(av[i + 2], O_RDONLY);
			if (fds[i] == -1)
			{
				perror("open");
				exit(EXIT_FAILURE);
			}
		}
	}
	return (fds);
}

/**
 * main - entry point.
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: EXIT SUCCESS or exit code
 */
int main(int ac, char *av[])
{
	int *fds;
	char *line;
	int i;
	int success = 1;

	fds = init_fds(ac, av);

	while (success)
	{
		success = 0;
		for (i = 0; fds[i] != -1; i++)
		{
			line = _getline(fds[i]);
			if (line)
			{
				success = 1;
				printf("%d %s\n", i, line);
				free(line);
			}
		}
	}
	_getline(-1);
	for (i = 0; fds[i] != -1; i++)
		close(fds[i]);
	free(fds);
	return (EXIT_SUCCESS);
}
