#include "multithreading.h"
#include <stddef.h>

img_t *iMageMap(blur_portion_t const *portion, size_t *surfaceArea, pixel_t *resolution[])
{
	size_t *width, *height;

	width = (size_t *)(portion->w);
	height = (size_t *)(portion->h);
	*surfaceArea = *width * *height;





	



}





















/**
 * blur_portion - apply gaussian blur to an image
 *
 * @portion: pointer to a stuct defining an image
 *
 */
void blur_portion(blur_portion_t const *portion)
{
	if (!portion || !portion->img || !portion->kernel)
	{
		printf("Error %d\n", errno);
		pthread_exit(0);
	}

	

}
