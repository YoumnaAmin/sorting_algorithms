#include "sort.h"

/**
 * _swap - to swap nodes
 * @head_ref: doubly linked list
 * @a:pointer to the list
 * @b: pointer to the list
 * Return: Nothing
*/

void _swap(listint_t **head_ref, listint_t *a, listint_t *b)
{
	if (a == b)
		return;

	if (a->prev != NULL)
		a->prev->next = b;

	if (b->next != NULL)
		b->next->prev = a;

	if (a->next == b)
	{
		a->next = b->next;
		b->prev = a->prev;
		a->prev = b;
		b->next = a;
	}

	else
	{
		listint_t *temp = a->prev;

		a->prev = b->prev;
		b->prev = temp;
		temp = a->next;
		a->next = b->next;
		b->next = temp;
	}

	if (a->prev == NULL)
		*head_ref = a;

	else if (b->prev == NULL)
		*head_ref = b;
}

/**
 * insertion_sort_list - sorting algorithm
 * @list: doubly linked list
 * Return: Nothing
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	while (current != NULL)
	{
		listint_t *prev = current->prev;

		while (prev != NULL && prev->n > current->n)
		{
			_swap(list, prev, current);
			prev = current->prev;
			print_list(*list);
		}
		current = current->next;
	}
}

/**
 * _free - to free list
 * @head: pointer to the list
 * Return: nothing
*/
void _free(listint_t *head)
{
	listint_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
