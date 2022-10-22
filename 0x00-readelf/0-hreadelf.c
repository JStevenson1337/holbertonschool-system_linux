#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - read elf file
 * @argc: argument length
 * @argv: the argument vector
 * @env:  the environment variable
 * Return: -1 in fail and 0 in success
 */
int main(int argc, char **argv, char **env)
{
	char *args[] = {"/usr/bin/readelf", "-W", "-h", "", NULL};

	(void)argc;
	args[3] = argv[1];
	if (execve("/usr/bin/readelf", args, env) == -1)
	{
		perror("execv");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
