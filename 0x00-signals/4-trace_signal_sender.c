#include "signals.h"

/**
 * signal_handler - traces caller
 * @signum: signal number
 * @siginfo: signal info
 * @ucontext: user context
 */
void signal_handler(int signum, siginfo_t *siginfo, void *ucontext)
{
	printf("SIGQUIT sent by %d\n", siginfo->si_pid);
	(void)signum;
	(void)ucontext;
}

/**
 * trace_signal_sender - traces SIGINT senders
 * Return: 0 on success else -1 on error
 */

int trace_signal_sender(void)
{
	struct sigaction act;

	memset(&act, 0, sizeof(act));
	act.sa_flags |= SA_SIGINFO;
	act.sa_sigaction = signal_handler;
	return (sigaction(SIGQUIT, &act, NULL));
}
