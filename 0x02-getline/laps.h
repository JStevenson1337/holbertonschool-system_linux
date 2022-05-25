#ifndef LAPS_H
#define LAPS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct car_s - struct that holds a car #id and the laps it's completed
 * @id: id number
 * @laps: laps the car has completed
 * @next: pointer to next car struct
 **/
typedef struct car_s
{
	int id;
	int laps;
	struct car_s *next;
} car_t;

void race_state(int *id, size_t size);
car_t *car_init(int id, car_t *next);
void free_car_list(car_t **cars);

#endif /* LAPS_H */
