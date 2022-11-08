#include "signals.h"
/**
 *
 *
 *
 *
 */
int handle_signal(void)
{

	if (signal(SIGINT, current_handler) == SIGINT)
		return (-1);
	printf("Gotcha! [%d]", signal);
  return (0);
}

