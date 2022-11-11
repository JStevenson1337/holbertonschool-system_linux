#include "signals.h"
/**
 * current_handler_signal - retrieves the current handler of the signal SIGINT
 * @my_sig: the signal number
 * Return: pointer to the current handler of SIGINT, or NULL on failure
 */
void signal_handler(int my_sig)
{
	printf("Gotcha! [%i]\n", my_sig);
	fflush(stdout);
}





/**
 * handle_signal - sets a handler for the signal SIGINT
 * Return: 0 on success, -1 on error
 */
int handle_sigaction(void)
{
	struct sigaction handle;

	memset(&handle, 0, sizeof(handle));
	handle.sa_handler = signal_handler;
	return(sigaction(SIGINT, &handle, NULL));

}
