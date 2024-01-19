#include "sort.h"

/**
 * bubble_sort - to sort an int
 * @array: pointor to array
 * @size: size of array
 * Return: no return
*/

void bubble_sort(int *array, size_t size)
{
	size_t temp, i, j;
	int swap;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < size - 1; j++)
	{
		swap = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap = 1;
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}
		if (swap == 0)
			break;
	}
}
