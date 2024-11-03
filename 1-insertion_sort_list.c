#include "sort.h"

/**
 * insertion_sort_list - sort list with insertion method
 * @list: list to be sorted
 * Return: success
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *back;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		while (temp->prev != NULL && (temp->n < temp->prev->n))
		{
			back = temp->prev;

			if (back->prev != NULL)
				back->prev->next = temp;
			temp->prev = back->prev;

			back->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = back;
			
			temp->next = back;
			back->prev = temp;
		
			if (temp->prev == NULL)
				*list = temp;

			print_list(*list);
		}
	}
}
