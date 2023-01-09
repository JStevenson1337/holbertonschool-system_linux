#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// extern char **environ;
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

	char *cmd = argv[1];
	char *args[] = {NULL};
	char *env[] = {NULL};

	execve(
		cmd,
		args,
		env
	);


	return 0;
}
