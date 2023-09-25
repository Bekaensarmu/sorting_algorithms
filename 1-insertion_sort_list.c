#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @n: A pointer to the head of the doubly-linked list.
 * @bek: A pointer to the first node to swap.
 * @len: The second node to swap.
 */
void swap_nodes(listint_t **n, listint_t **bek, listint_t *len)
{
	(*bek)->next = len->next;
	if (len->next != NULL)
		len->next->prev = *bek;
	len->prev = (*bek)->prev;
	len->next = *bek;
	if ((*bek)->prev != NULL)
		(*bek)->prev->next = len;
	else
		*n = len;
	(*bek)->prev = len;
	*bek = len->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
