#include "signals.h"

/**
 * current_handler_sigaction - retrieves the current handler of the signal SIGINT
 * Return: pointer to the current handler of SIGINT, or NULL on failure
 *
 */
void (*current_handler_sigaction(void))(int)
{
	struct sigaction prev;

	memset(&prev, 0, sizeof(prev));
	if (sigaction(SIGINT, NULL, &prev) == -1)
		return (NULL);
	return (prev.sa_handler);
}

