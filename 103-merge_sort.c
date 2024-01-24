#include <stdlib.h>
#include "sort.h"

/**
 * copy_sortedarray - copies data from one buffer to another
 *
 * @src: source buffer
 * @dst: destination buffer
 * @size: size of buffers
 *
 * Return: No Return
 */
void copy_sortedarray(int *src, int *dst, int size)
{
	int i;

	for (i = 0; i < size; i++)
		dst[i] = src[i];
}
/**
 * printcheck - prints an array in a given range
 *
 * @array: array of data to be print
 * @r1: start of range
 * @r2: end of range
 *
 * Return: No Return
 */
void printcheck(int *array, int r1, int r2)
{
	int i;

	for (i = r1; i <= r2; i++)
	{
		if (i > r1)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}


void merge(int *array, int *sorted_array, int min, int max, int mid);
/**
 * mergeSort - to sort the array
 * @array: the original array
 * @buff: sorted array
 * @min: the Left most pos
 * @max: the right most pos
 * @size: size of original array
 * Return: no return
*/
void mergeSort(int *array, int *buff, int min, int max, size_t size)
{
	if (min < max)
	{
		int mid = (min + max) / 2;

		mergeSort(array, buff, min, mid, size);
		printf("Merging...\n");
		printf("[left]: ");
		printcheck(array, min, mid);

		printf("[right]: ");
		printcheck(array, mid + 1, max);

		mergeSort(array, buff, mid + 1, max, size);
		merge(array, buff, min, max, mid);
		copy_sortedarray(array, buff, size);
		printf("[Done]: ");
		printcheck(array, min, max);
	}
}

/**
 * merge - to sort the array
 * @array: the original array
 * @sorted_array: the sorted array
 * @min: the Left most pos
 * @max: the right most pos
 * @mid: themid point of the array
 * Return: no return
*/
void merge(int *array, int *sorted_array, int min, int max, int mid)
{
	int i, j, k;

	i = min;
	j = mid + 1;
	k = 0;
	while (i <= mid && j <= max)
	{
		if (array[i] <= array[j])
		{
			sorted_array[k] = array[i];
			i++;
		}
		else
		{
			sorted_array[k] = array[j];
			j++;
		}
		k++;
	}
	while (i <= mid)
	{
		sorted_array[k] = array[i];
		i++;
		k++;
	}
	while (j <= max)
	{
		sorted_array[k] = array[j];
		j++;
		k++;
	}
}

/**
 * merge_sort - to sort the array
 * @array: the orginal array
 * @size: the size of the array
 * Return: no return
*/

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
	{
		return;
	}
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	copy_sortedarray(array, buff, size);
	mergeSort(array, buff, 0, size - 1, size);
	free(buff);
}
