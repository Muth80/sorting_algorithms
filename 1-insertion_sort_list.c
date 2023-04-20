#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                        order using the Insertion sort algorithm.
 *
 * @list: Double pointer to the head of the doubly linked list.
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL, *tmp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;

	while (curr != NULL)
	{
		tmp = curr->prev;
		while (tmp != NULL && tmp->n > curr->n)
		{
			swap_nodes(tmp, curr);
			if (tmp->prev == NULL)
				*list = tmp;
			print_list(*list);
			tmp = curr->prev;
		}
		curr = curr->next;
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @node1: Pointer to the first node to swap
 * @node2: Pointer to the second node to swap
 */
void swap_nodes(listint_t *node1, listint_t *node2)
{
	listint_t *tmp;

	if (!node1 || !node2)
		return;

	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;

	tmp = node2->next;
	node2->next = node1;
	node1->next = tmp;
	tmp = node1->prev;
	node1->prev = node2;
	node2->prev = tmp;
}

