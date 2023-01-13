#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/* Global Variable */
int a = 0;

void *func(void *var)
{
	int *id = (int *)var;
	static int b = 0;

	b = 7;
	a = 7;

	printf("thread id = %d\n", *id);
	printf("static var id = %d\n", b);
	printf("global var = %d\n", a);
}

int main()
{
	pthread_t th_id;

	for (int i = 0; i < 10; i++)
	{
		pthread_create(&th_id, NULL, func, (void*)&th_id);

	}
	pthread_exit(NULL);
	exit(0);
	
}

