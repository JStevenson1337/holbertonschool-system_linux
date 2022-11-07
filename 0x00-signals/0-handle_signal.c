#include "signals.h"
/**
 *
 *
 *
 *
 */
int handle_signal(void)
{
	my_sig_t handler;


	if (signal(SIGINT, handler) == SIGINT)
		return (-1);
	write(1, "Gotcha!  \n", );
	return (0);
}
