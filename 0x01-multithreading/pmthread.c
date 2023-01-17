#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>

pthread_mutex_t locked;

int a;

void procFunc()
{
	pthread_mutex_lock(&locked);

	int i = 0;

	a++;

	while (i < 6)
	{
		printf("%d\n", a);
		sleep(3);

		i++;
	}
	printf("Finished..");

	pthread_mutex_unlock(&locked);
}


int main()
{
	int error;
	pthread_t th1, th2;

	if (pthread_mutex_init(&locked, NULL) != 0)
	{
		printf("Mutex Failed\n");
		exit(1);

	}
	
	a = 0;
	pthread_create(&th1, NULL, procFunc, NULL);
	pthread_create(&th2, NULL, procFunc, NULL);

	pthread_join(th1, NULL);
	
	return (0);

}
