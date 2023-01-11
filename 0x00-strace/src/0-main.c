#include "../inc/header.h"
#include "../inc/syscalls.h"
#include <stdlib.h>
/**
 * main - Entry Point
 * argc: argument count
 * argv: argument vector
 * environ: environment variables
 */
int main(int argc, char *argv[], char **environ)
{
	pid_t pid;
	int stat_loc, in_syscall = 0;
	unsigned long syscall_nb;
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
		ptrace(PTRACE_TRACEME, 0, 0, 0);
		execve(argv[1], &argv[1], environ);
	}
	else if (pid > 0)
	{
		wait(&stat_loc);

		while ((stat_loc >> 8) == SIGTRAP && (stat_loc & 0xFF) == stat_loc)
		{
			if (!in_syscall)
			{

				ptrace(PTRACE_GETREGS, pid, NULL, &regs);

				syscall_nb = (unsigned long)regs.orig_rax;

				printf("%lu\n", syscall_nb);
				in_syscall = 1;
			}
			else
			{
				in_syscall = 0;
			}
			ptrace(PTRACE_SYSCALL, pid, NULL, &regs);
			wait(&stat_loc);
			fflush(stdout);
		}	
	}
	return (EXIT_SUCCESS);
}
