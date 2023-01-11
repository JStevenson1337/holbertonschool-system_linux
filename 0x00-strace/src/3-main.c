#include "../inc/header.h"
#include "../inc/syscalls.h"

/**
 * print_args - print system call arguments
 * @sc: pointer to syscall struct
 * @regs: registers (struct user_regs_struct)
 * @pid: pid (unused)
 **/
void print_args(const syscall_t *sc, struct user_regs_struct *regs, pid_t pid)
{
	size_t i, params[MAX_PARAMS];

	(void)pid;

	params[0] = regs->rdi, params[1] = regs->rsi, params[2] = regs->rdx;
	params[3] = regs->r10, params[4] = regs->r8, params[5] = regs->r9;

	putchar('(');
	for (i = 0; sc->params[0] != VOID && i < sc->nb_params; i++)
		if (sc->params[i] == VARARGS)
			printf("%s...", i ? ", " : "");
		else
			printf("%s%#lx", i ? ", " : "", params[i]);
}

/**
 * main - traces a process and prints system call numbers
 * @argc: argument count
 * @argv: argument array
 * @envp: environment parameters
 * Return: 0 on success | 1 on failure (not enough arguments)
 **/
int main(int argc, char *argv[], char *envp[])
{
	int skip, status;
	struct user_regs_struct regs;
	pid_t pid;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <full_path> [path_args]\n", argv[0]);
		return (1);
	}
	setbuf(stdout, NULL);
	pid = fork();
	if (pid == 0)
	{
		printf("execve(0, 0, 0");
		ptrace(PTRACE_TRACEME, pid, NULL, NULL);
		execve(argv[1], argv + 1, envp);
	}
	else
	{
		for (status = 1, skip = 0; !WIFEXITED(status); skip ^= 1)
		{
			ptrace(PT_SYSCALL, pid, NULL, NULL);
			wait(&status);
			ptrace(PT_GETREGS, pid, NULL, &regs);
			if (skip)
			{
				printf("\n%s", syscalls_64_g[regs.orig_rax].name);
				print_args(&syscalls_64_g[regs.orig_rax], &regs, pid);
			}
			else
			{
				if (WIFEXITED(status))
					printf(") = ?\n");
				else
					printf(") = %#lx", (size_t)regs.rax);
			}
		}
	}

	return (0);
}
