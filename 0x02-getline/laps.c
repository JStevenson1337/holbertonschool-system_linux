#include "laps.h"

/**
 * race_state - keeps track of laps made by several cars in a race
 * @id: array of ints representing the id for each car in the race
 * @size: size of id array
 **/
void race_state(int *id, size_t size)
{
	static car_t *cars;
	car_t *next, *prev, *new;

	if (size == 0) /* if size is 0, reset cars list */
	{
		for (; cars; cars = next)
			next = cars->next, free(cars);
		return;
	}

	for (; size--; id++) /* Loop through all ids */
	{
		/* For each id, stop when *id <= current node or list is done */
		for (prev = NULL, next = cars; next; prev = next, next = next->next)
			if (*id <= next->id)
				break;

		if (next && *id == next->id) /* If id found, increment laps */
		{
			next->laps += 1;
		}
		else /* else, add new node to list */
		{
			printf("Car %d joined the race\n", *id);
			new = malloc(sizeof(car_t));
			if (new == NULL)
				return;
			new->id = *id;
			new->laps = 0;
			new->next = next;
			if (prev)
				prev->next = new;
			else
				cars = new;
		}
	}

	printf("Race state:\n");
	for (next = cars; next; next = next->next) /* Print list */
		printf("Car %d [%d laps]\n", next->id, next->laps);
}
