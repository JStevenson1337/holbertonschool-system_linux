#include "../inc/header.h"


/**
 * main - Entry Point
 * argc: argument count
 * argv: argument vector
 *
 * ONLY parameter to be passed in 
 * fully qualified path of binary file
 *      ie "./ex0 /usr/bin/ls"
*/
int main(int argc, char *argv[], char **environ)
{

	if (argc < 2)
	{
		printf("Error -> %i\n", errno);
		return(EXIT_FAILURE);
	}
	/* fork */
	/* 
	   if 0 in child
	   if greater in parent
	   else fork failed 
	*/
	execve(
		argv[1],
		&argv[1],
		environ
	);
	printf(">>> Error = %i\n", errno);


	return 0;
}
