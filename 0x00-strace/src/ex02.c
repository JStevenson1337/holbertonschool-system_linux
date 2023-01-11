#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../inc/header.h" /* Helper header from project instructions */

int main(int argc, char ** argv, char ** envp)
{
	pid_t pid;
	struct user_regs_struct reg;

	/* Validate command-line args here, EXIT_FAILURE if no child command given*/

	pid = fork();

	if (pid == 0)
	{
		/* In child process, mark process for tracing and execve the cmd */
		ptrace(PTRACE_TRACEME, 0, NULL, NULL);
		execve(argv[1], argv + 1, envp);
		/* If execve returns, then it failed, so EXIT_FAILURE here */
	}
	else if (pid > 0)
	{
		/* In parent process, intercept child's syscalls */
		int status, in_syscall = 0;
		unsigned long syscall_nb;

		/* Wait for execve to finish */
		wait(&status);

		/* Child-process status has 16 significant bits
		 *   Upper 8 bits indicate the signal (we want SIGTRAP)
		 *   Lower 8 indicate child is stopped if equal to 0177 (octal)
		 * Alternatively, you could just use `while(status == 1407)` but that's even more opaque
		 */
		while ((status >> 8) == SIGTRAP && (status & 0xFF) == stat_loc)
		{
			if (!in_syscall)
			{
				/* Stopped after the syscall, get register data here */
				/* Get register values */
				ptrace(PTRACE_GETREGS, pid, NULL, &reg);

				/* Syscall number in orig_rax */
				syscall_nb = (unsigned long)reg.orig_rax;

				/* Print syscall number*/
				printf("%lu\n", syscall_nb);
				in_syscall = 1;

				/* For parts 1-8...
				 * You'll use the syscall number to find data in syscalls_64_g array
				 */
			}
			else
			{
				/* Stopped during the syscall, get data on next interation */
				in_syscall = 0;
			}

			ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
			wait(&status);
		}	
	}
	else
	{
		/* Fork failed, EXIT_FAILURE here */
	}
	
	return (EXIT_SUCCESS);
}
