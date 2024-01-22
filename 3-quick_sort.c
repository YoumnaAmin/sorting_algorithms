#include "sort.h"

/**
 * partition - to divide and conqure
 * @array: data to part
 * @size: size of data
 * @low: lowest pos
 * @high: highest pos
 * Return: int
*/

int partition(int *array, int low, int high, size_t size)
{
	int pivot, tmp;
	int i, j;

	pivot = array[high];
	i = low;
	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			if (array[i] != array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	tmp = array[i];
	array[i] = array[high];
	array[high] = tmp;
	print_array(array, size);
	return (i);
}

/**
 * quicksort -  sorts an array of integers
 * @array: data to sort
 * @min: Left wall
 * @max: right wall
 * @size: size of data
 * Return: No Return
 */
void quicksort(int *array, int min, int max, size_t size)
{
	int p;

	if (min < max)
	{
		p = partition(array, min, max, size);
		quicksort(array, min, p - 1, size);
		quicksort(array, p + 1, max, size);
	}
}

/**
 * quick_sort - sorts an array of integers
 * @array: data to sort
 * @size: size of data
 * Return: No Return
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
