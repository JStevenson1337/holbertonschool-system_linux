#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - Executes the command readelf -W -h to show information of the header
 * tables in the ELF files
 *
 * @argc: count of inputs
 * @argv: arguments received by the program
 * @env: enviroment variables to execute readelf
 *
 * Return: 0 if success 1 otherwise
 */
int main(int argc, char *argv[], char *env[])
{
	char *command = "/usr/bin/nm";
	char *arguments[4];

	(void) argc;
	arguments[0] = "./hnm";
	arguments[1] = "-p";
	arguments[2] = argv[1];
	arguments[3] = NULL;
	if (execve(command, arguments, env) == -1)
	{
		perror("Error: ");
		exit(1);
	}
	return (0);
}
