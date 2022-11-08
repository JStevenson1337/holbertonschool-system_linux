#include "signals.h"

/**
 * signal_handler - prints a message when a signal is received
 * @my_sig: the signal number
 */
void signal_handler(int my_sig)
{
	printf("Gotcha! [%d]\n", my_sig);
	fflush(stdout);
}

/**
 * handle_signal - sets a handler for the signal SIGINT
 * Return: 0 on success, -1 on error
 */
int handle_signal(void)
{
	if (signal(SIGINT, signal_handler) == SIG_ERR)
		return (-1);
	return (0);
}
