#include "../inc/header.h"
#include "../inc/syscalls.h"
#include <stdlib.h>
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
	int stat_loc;




	while (mainThread)
	{
		pid = fork();

		if (pid == -1)
		{
			printf("errno %i\n", errno);
			return (EXIT_FAILURE);
		}
		if ( pid == 0)
		{
			ptrace(PTRACE_TRACEME, 0, 0, 0);

			/* Execute the process */
			argv[argc] = 0;

			execve(argv[1], &argv[1], NULL);
			/*TODO: The success of execve will cause a
			SIGTRAP to be sent to this child process. */
			
			

		}
		/* In parent */

		/* Wait for execve to finish*/

		pid_t wait(int *stat_loc);
		/* Start to trace system calls */

		ptrace(PTRACE_SYSCALL, pid, 0, 0);
		/* TODO: Wait until the ennty to a sys call */
		sysInfo[0] = {nr};
		struct user_regs_struct u_in;
		/* TODO: Fill Struct */

		ptrace(PTRACE_GETREGS, pid, 0, &u_in);
		

		syscall = u_in.orig_eax;
		/* TODO: Restart Child if stopped */
		
		if (syscall == __NR_open)
		{
			printf("%s", syscall_names[syscall-1]);
 			printf("%08lx ", u_in.ebx);
			printf("%08lx ", u_in.ecx);
			printf("%08lx\n ", u_in.edx);
		}
		mainThread--;
	}
	
	return 0;
}
