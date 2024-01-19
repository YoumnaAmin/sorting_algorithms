#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 * @array: data to sort
 * @size: size of data
 * Return: No Return
 */

void selection_sort(int *array, size_t size)
{
	size_t pos, i, j;
	int swap, min;

	if (array == NULL || size < 2)
		return;

	swap = 0;
	for (j = 0; j < size; j++)
	{
		min = array[j];
		pos = j;
		for (i = j + 1; i < size ; i++)
		{
			if (min > array[i])
			{
				min = array[i];
				pos = i;
				swap = 1;
			}
		}
		array[pos] = array[j];
		array[j] = min;
		if (swap)
			print_array(array, size), swap = 0;
	}
}
