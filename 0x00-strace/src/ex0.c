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
	int currArg;
	char *cmd = argv[1];
	char *args[] = {};
	// char **environ};

	if (argc == 1)
	{
		printf("No Command passed to %s\n", argv[0]);
	}
	if (argc > 2)
	{
		printf("Here!\n");
	}
	for (currArg = 0; currArg < argc; currArg++)
	{
		printf("%s\n", argv[currArg]);
		// snprintf(args, sizeof(argv), "%s", argv);
	}
	// memcpy(&args, argv, sizeof(char **));
	*args -> argv;
	execve(
		cmd,
		args,
		environ
	);
	printf(">>> Error = %i\n", errno);


	return 0;
}
