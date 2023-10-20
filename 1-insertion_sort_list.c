#include "sort.h"
#include <stdlib.h>

/**
 * swap_nodes - Swap two nodes in a doubly linked list
 * @node1: A pointer to a pointer to the first node to swap
 * @node2: A pointer to the second node to be swapped with
 * @h: A pointer to the head of the list
 *
 * Return: Nothing!
 */
void swap_nodes(listint_t **h, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*h = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using
 * 			the Insertion algorithm
 * @list: A pointer to the list
 *
 * Return: Nothing!
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *temp;
	listint_t *insert;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		insert = i->prev;
		while (insert != NULL && i->n < insert->n)
		{
			swap_nodes(list, &insert, i);
			print_list((const listint_t *)*list);
		}
	}
}
