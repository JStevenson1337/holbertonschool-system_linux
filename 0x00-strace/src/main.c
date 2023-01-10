#include "../inc/header.h"
#include <sys/ptrace.h>


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
	pid_t pid;
	long orig_eax;
	
	if (pid == 0)
	{
		/* TODO: Inside Child Process */
		pid_t cPid = pid;

		ptrace(PTRACE_TRACEME, cPid, NULL, NULL);

		execve(argv[1],&argv[1],environ);
		/* Execve Faild */
		printf(">>> Error = %i\n", errno);
		return (EXIT_FAILURE);
	}
	
	if (pid > 0)
	{
		// int wait(NULL);
		// orig_eax = ptrace(PTRACE_GETREGS, )
		/* TODO: Inside Parent Process */
		pid_t pPid = pid;
	}
	else
	{
		/* Fork Failed Exit */
		printf("Error = %i\n", errno);
		return (EXIT_FAILURE);
	}

	if (argc < 2)
	{
		printf("Error -> %i\n", errno);
		return(EXIT_FAILURE);
	}
	/* fork */
	
	/* TODO: if 0 in child; if greater in parent; else fork failed */
		
		
	// execve(
	// 	argv[1],
	// 	&argv[1],
	// 	environ
	//);
	


	return 0;
}
