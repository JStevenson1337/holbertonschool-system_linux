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
  int stat_loc, end_loc = 1;
  struct user_regs_struct reg;

  pid = fork();

  if (pid == -1) {
    printf("errno %i\n", errno);
    return (EXIT_FAILURE);
  }
  if (pid == 0) {
    ptrace(PTRACE_TRACEME, 0, 0, 0);
    /* Execute the process */
    execve(argv[1], &argv[1], environ);

  } else if (pid > 0) {
    wait(&stat_loc);

    while ((stat_loc >> 8) == SIGTRAP && (stat_loc & 0xFF) == stat_loc) {
      if (!sysInfo.nr) {
        /* Stopped after the syscall, get register data here */
        /* Get register values */
        ptrace(PTRACE_GETREGS, pid, NULL, &reg);

        /* Syscall number in orig_rax */
        sysInfo.nr

            /* Print syscall number*/
            printf("%lu\n", sysInfo.nr);
        sysInfo.nb_params = 1;

        /* For parts 1-8...
         * You'll use the syscall number to find data in syscalls_64_g array
         */
      } else {
        /* Stopped during the syscall, get data on next interation */
        &sysInfo.nr = 0;
      }

      ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
      wait(&status);
    }
  } else {
    /* Fork failed, EXIT_FAILURE here */
  }

  return (EXIT_SUCCESS);
