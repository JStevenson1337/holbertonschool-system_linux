#ifndef __SIGNALS_H__
#define __SIGNALS_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <signal.h>

typedef struct signal_t {
	int sig;
	int signum;
	char *name;
	char *desc;
}my_sig_t;

struct signal_t signals[] = {
	{SIGHUP, 1, "SIGHUP", "Hangup (POSIX)."},
	{SIGINT, 2, "SIGINT", "Interrupt (ANSI)."},
	{SIGQUIT, 3, "SIGQUIT", "Quit (POSIX)."},
	{SIGILL, 4, "SIGILL", "Illegal instruction (ANSI)."},
	{SIGTRAP, 5, "SIGTRAP", "Trace trap (POSIX)."},
	{SIGABRT, 6, "SIGABRT", "Abort (ANSI)."},
	{SIGIOT, 6, "SIGIOT", "IOT trap (4.2 BSD)."},
	{SIGBUS, 7, "SIGBUS", "BUS error (4.2 BSD)."},
	{SIGFPE, 8, "SIGFPE", "Floating-point exception (ANSI)."},
	{SIGKILL, 9, "SIGKILL", "Kill, unblockable (POSIX)."},
	{SIGUSR1, 10, "SIGUSR1", "User-defined signal 1 (POSIX)."},
	{SIGSEGV, 11, "SIGSEGV", "Segmentation violation (ANSI)."},
	{SIGUSR2, 12, "SIGUSR2", "User-defined signal 2 (POSIX)."},
	{SIGPIPE, 13, "SIGPIPE", "Broken pipe (POSIX)."},
	{SIGALRM, 14, "SIGALRM", "Alarm clock (POSIX)."},
	{SIGTERM, 15, "SIGTERM", "Termination (ANSI)."},
	{SIGSTKFLT, 16, "SIGSTKFLT", "Stack fault."},
	{SIGCHLD, 17, "SIGCHLD", "Child status has changed (POSIX)."},
	{SIGCONT, 18, "SIGCONT", "Continue (POSIX)."},
	{SIGSTOP, 19, "SIGSTOP", "Stop, unblockable (POSIX)."},
	{SIGTSTP, 20, "SIGTSTP", "Keyboard stop (POSIX)."},
	{SIGTTIN, 21, "SIGTTIN", "Background read from tty (POSIX)."},
	{NULL, 0, NULL, NULL}
};


// Signal handler
int handle_signal(void);



#endif /* __SIGNALS_H__ */
