#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
extern char **environ;

/**
 * main - Entry Point
 * argc: argument count
 * argv: argument vector
 *
 * ONLY parameter to be passed in 
 * fully qualified path of binary file
 *      ie "./ex0 /usr/bin/ls"
*/
int main(int argc, char *argv[])
{

	if (argc < 2)
	{
		printf("Error -> %i\n", errno);
		return(EXIT_FAILURE);
	}
	execve(
		argv[1],
		&argv[1],
		environ
	);
	printf(">>> Error = %i\n", errno);


	return 0;
}
