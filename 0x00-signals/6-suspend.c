#include "signals.h"

/**
 * signal_handler - kills self
 * @signum: the signal number
 * @siginfo: info struct about signal
 * @user_context: pointer to user_context_t
 */
void signal_handler(int signum, siginfo_t *siginfo, void *user_context)
{
	printf("Caught %d\n", signum);
	fflush(stdout);
	(void)siginfo;
	(void)user_context;
}

/**
 * set_signal - sets the signal here
 * Return: 0 on success else -1 on error
 */

int set_signal(void)
{
	struct sigaction act;

	memset(&act, 0, sizeof(act));
	act.sa_flags |= SA_SIGINFO;
	act.sa_sigaction = signal_handler;
	return (sigaction(SIGINT, &act, NULL));
}

/**
 * main - entry point
 * Return: Always success
 */
int main(void)
{
	set_signal();
	pause();
	printf("Signal received\n");
	return (EXIT_SUCCESS);
}
