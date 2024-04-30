#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * of integers in ascending order
 *
 * @list: a doubly linked list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;
	listint_t *temp;


	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;


	while (current)
	{
		temp = current;

		while (temp->prev && temp->n < temp->prev->n)
		{
			listint_t *next_node = temp->next;
			listint_t *prev_node = temp->prev;

			if (next_node)
				next_node->prev = prev_node;
			prev_node->next = next_node;

			temp->next = prev_node;
			temp->prev = prev_node->prev;

			if (temp->prev)
				temp->prev->next = temp;

			prev_node->prev = temp;

			if (!temp->prev)
				*list = temp;

			print_list(*list);
		}

		current = current->next;
	}
}
