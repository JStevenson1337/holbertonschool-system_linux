#include "signals.h"

/**
 * print_hello - prints a message when a signal is received
 * @my_sig: the signal number
 */
void print_hello(int my_sig)
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
	if (signal(SIGINT, print_hello) == SIG_ERR)
		return (-1);
	return (0);
}
