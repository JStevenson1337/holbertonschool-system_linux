#include "../inc/header.h"
#include "../inc/syscalls.h"
/**
 * main - Entry Point
 * argc: argument count
 * argv: argument vector
 * environ: environment variables
 */
int main(int argc, char *argv[], char **environ)
{
	pid_t pid;
	int stat_loc, showCall;
	struct user_regs_struct regs;

	pid = fork();
	if (argc < 1)
	{
		printf("No Executable Path Specified for %s,\n", argv[0]);
		return (EXIT_FAILURE);
	}

	if (pid == -1)
	{
		printf("errno %i\n", errno);
		return (EXIT_FAILURE);
	}
	if (pid == 0)
	{
		
		ptrace(PTRACE_TRACEME, pid, NULL, NULL);
		execve(argv[1], argv + 1, environ);
	}
	else
	{
		for (stat_loc = 1, showCall = 0; !WIFEXITED(stat_loc); showCall ^= 1)
		{
			ptrace(PT_SYSCALL, pid, NULL, NULL);
			wait(&stat_loc);
			printf("59\n");
			ptrace(PT_GETREGS, pid, NULL, &regs);
			if (showCall)
				printf("%lu\n", (size_t)regs.orig_rax);
		}
	}
	return (EXIT_SUCCESS);

}
	

