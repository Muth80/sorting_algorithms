#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm
 * @list: double pointer to the head of the list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 0;
	listint_t *start = *list;
	listint_t *end = NULL;
	listint_t *current = NULL;

	if (!list || !(*list) || !((*list)->next))
		return;

	do {
		swapped = 0;

		for (current = start; current->next != end; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next);
				print_list(*list);
				swapped = 1;
			}
		}

		if (swapped == 0)
			break;

		end = current;

		for (current = current->prev; current != start->prev; current =
		current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(current->prev, current);
				print_list(*list);
				swapped = 1;
			}
		}

		start = current->next;
	} while (swapped);
}

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @node1: pointer to the first node
 * @node2: pointer to the second node
 *
 * Return: void
 */

void swap_nodes(listint_t *node1, listint_t *node2)
{
	int temp = node1->n;

	node1->n = node2->n;
	node2->n = temp;
}
