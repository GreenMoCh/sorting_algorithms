#include "sort.h"

/**
 * insertion_sort_list - Sort a doubly linked list of ints in ascending order
 *
 * @list: A ptr to a ptr to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	if (!list || !*list || !(*list)->next)
		return;
	current = (*list)->next;

	while (current)
	{
		prev = current->prev;

		while (prev && prev->n > current->n)
		{
			if (current->next)
				current->next->prev = prev;

			prev->next = current->next;
			current->prev = prev->prev;
			current->next = prev;
			prev->prev = current;

			if (current->prev)
				current->prev->next = current;
			else
				*list = current;

			prev = current->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
