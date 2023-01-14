#include "multithreading.h"
#include <stdlib.h>



void *thread_entry(void *arg)
{
	// char *str;
	// int i = 0;

	// str = (char *)arg;
	if (arg == NULL)
	{
		pthread_exit(&arg);
	}
	return (0);
}

