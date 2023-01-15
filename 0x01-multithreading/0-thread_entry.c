#include "multithreading.h"
/**
  * thread_entry - entry point for a new thread
  *
  * @arg: pointer to the address of a string
  * Return: pointer
  */
void *thread_entry(void *arg)
{
	void *str;

	str = (char *)arg;

	if (str == NULL)
	{
		pthread_exit(&str);
	}

	printf("%s\n", (char *)str);
	pthread_exit(NULL);
}

