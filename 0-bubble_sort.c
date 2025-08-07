#include <stdio.h>
#include "sort.h"
/**
 * bubble_sort - sorts an array of integers
 * @array: array to sort
 * @size: the size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;
	int swap = 0;

	if (array == NULL || size < 2)
	{
	return;
	}
	for (i = 0; i < size - 1; i++)
	{
	for (j = 0; j < size -  i - 1; j++)
	{
		if (array[j] > array[j + 1])
		{
		tmp = array[j];
		array[j] = array[j + 1];
		array[j + 1] = tmp;
		swap = 1;
		print_array(array , size);
		}

	}
	if (swap == 0)
	{
	break;
	}

	}
}
