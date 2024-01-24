#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int partition(int *array, int low, int high, size_t size);
void quicksort(int *array, int min, int max, size_t size);
void _swap(listint_t **head_ref, listint_t *a, listint_t *b);
void counting_sort(int *array, size_t size);
void merge(int *array, int *sorted_array, int min, int max, int mid);
void mergeSort(int *array, int *buff, int min, int max, size_t size);
void merge_sort(int *array, size_t size);
void printcheck(int *array, int r1, int r2);
void copy_sortedarray(int *src, int *dst, int size);
#endif
