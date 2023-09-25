#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of ints in ascending order
 *
 * @list: A ptr to a ptr to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current = NULL;

	if (list == NULL || *list == NULL)
		return;
	while (swapped)
	{
		swapped = 0;
		current = *list;

		while (current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &current, &(current->next));
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}
		if (!swapped)
			break;
		swapped = 0;

		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, &(current->prev), &current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: A ptr to a ptr to the head of the list
 * @a: ptr to the first node to swap
 * @b: ptr to the second node to swap
 */
void swap_nodes(listint_t **list, listint_t **a, listint_t **b)
{
	listint_t *prev_a = (*a)->prev;
	listint_t *next_b = (*b)->next;

	if (prev_a)
		prev_a->next = *b;
	else
		*list = *b;
	(*b)->prev = prev_a;
	(*b)->next = *a;
	(*a)->prev = *b;
	(*a)->next = next_b;

	if (next_b)
		next_b->prev = *a;
}
