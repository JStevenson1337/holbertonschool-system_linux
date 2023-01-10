#include "../inc/header.h"
#include "../inc/syscalls.h"
/**
 * main - Entry Point
 * argc: argument count
 * argv: argument vector
 * environ: environment variables
 */
int main(int argc, char *argv[], char **environ) {
	pid_t pid;
	syscall_t sysInfo;
	int mainThread = 1;




  while (mainThread)
  {
	pid = fork();

	printf("%d\t initial Fork\n", pid);

	if (pid == 0)
	{
		printf("%d\t inside Child Condition\n", pid);

		ptrace(PTRACE_TRACEME, pid, NULL, NULL);

		execve(argv[1], &argv[1], NULL);
		/* Execve Faild */
		printf(">>> Error = %i\n", errno);
		return (EXIT_FAILURE);
	}

	if (pid > 0)
	{

		// int wait(NULL);
		// orig_eax = ptrace(PTRACE_GETREGS, )
		/* TODO: Inside Parent Process */
		// pid_t pPid = pid;
		printf("%d\t inside Parent Condition\n", pid);
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
		return (EXIT_FAILURE);
	}

	mainThread--;
	}

	return 0;
}
