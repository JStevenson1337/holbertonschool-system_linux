#include "multithreading.h"
#include <pthread.h>
/**
 * blur_portion - apply gaussian blur to an image
 *
 * @portion: pointer to a stuct defining an image
 *
 */
void blur_portion(blur_portion_t const *portion)
{
	/* TODO: pthread_t tid; */
	/* TODO: create atributes */
	/* TODO: init  */
	/* TODO:pthread create id &attr function caller,  address of img?*/


	/* TODO:join */


	if (!portion)
	{
		pthread_exit(NULL);
	}
	pthread_attr_init((pthread_attr_t *)portion);



}
