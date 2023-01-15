#include "multithreading.h"
#include <stdlib.h>
/**
  * thread_entry - entry point for a new thread
  *
  * @arg: pointer to the address of a string
  * @Return: 0 = Success -1 = Failure
  */
void *thread_entry(void *arg)
{
	if (arg == NULL)
	{
		pthread_exit(&arg);
	}

	printf("%s\n", (char *)arg);
	pthread_exit(&arg);
	return (0);
}

