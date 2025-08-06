#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: the list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *left, *right;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			left = temp->prev;
			right = temp->next;

			if (left->prev != NULL)
				left->prev->next = temp;
			else
				*list = temp;

			if (right != NULL)
				right->prev = left;

			temp->prev = left->prev;
			left->next = right;
			temp->next = left;
			left->prev = temp;
			print_list(*list);
		}
	}
}
