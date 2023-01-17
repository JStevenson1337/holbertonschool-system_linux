#include "multithreading.h"
#include <stddef.h>
/**
 * blur_portion - apply gaussian blur to an image
 *
 * @portion: pointer to a stuct defining an image
 *
 */
void blur_portion(blur_portion_t const *portion)
{
	size_t *width, *height, *SA;

	width = (size_t *)(portion->w);
	height = (size_t *)(portion->h);
	


	if (!portion || !portion->img || !portion->kernel)
	{
		printf("Error %d\n", errno);
		pthread_exit(0);
	}

	*SA = *width * *height;

}
