#include <stdlib.h>
#include "sort.h"
int lemuto_partition(int *array, int low, int high, size_t size);
/**
 * swap - Swaps two integers in an array
 * @a: Pointer to first integer
 * @b: Pointer to second integer
 */
void swap(int *a, int *b )
{
	int tmp;
	if (*a != *b)
	{
	tmp = *a;
	*a = *b;
	*b = tmp;
	}
}
/**
 * qs_recusive - Recursively applies quicksort use lemuto
 * @array: Array to sort
 * @low: Starting index of the sub-array
 * @high: Ending index of the sub-array
 * @size: Total size of the array
 */
void qs_recusive(int *array, int low, int high, size_t size)
{
	if (low < high)
    {
	int pivot = lemuto_partition(array, low, high, size);
	qs_recusive(array, low, pivot - 1, size);
	qs_recusive(array, pivot + 1, high, size);
	}	
}
/**
 * lemuto_partition - Partitions the array using Lomuto scheme
 * @array: Array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Total size of the array
 * Return: Index of the pivot after partition
 */
int lemuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
        {
		swap(&array[low], &array[j]);
		print_array(array, size);
		low++;
		}
	}
	swap(&array[low], &array[high]);
	print_array(array, size);
	return (low);
}
/**
 * quick_sort - Sorts an array using quicksort
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
	return;
	}
	qs_recusive(array, 0, size - 1, size);    
}
