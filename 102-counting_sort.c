#include "sort.h"
/**
 * counting_sort - sorting algorithm
 * @array: array of int
 * @size: size of array
 * Return: no thing
*/

void counting_sort(int *array, size_t size)
{
	int j, k, mx;
	size_t i;
	int *count_array, *output_array;

	if (array == NULL || size < 2)
		return;
	mx = 0;
	for (i = 0; i < size; i++)
	{
		if (array[i] > mx)
			mx = array[i];
	}

	count_array = (int *)malloc((mx + 1) * sizeof(int));

	output_array = (int *)malloc(size * sizeof(int));
	for (i = 0; i < size; i++)
		output_array[i] = 0;

	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	for (k = 1; k <= mx; k++)
		count_array[k] += count_array[k - 1];

	print_array(count_array, mx);

	for (j = size - 1; j >= 0; j--)
	{
		output_array[count_array[array[j]] - 1] = array[j];
		count_array[array[j]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output_array[i];

	free(count_array);
	free(output_array);
}
