#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @bekList: Dobule linked list to sort
 */
void insertion_sort_list(listint_t **bekList)
{
	listint_t *bekNode;

	if (bekList == NULL || (*bekList)->next == NULL)
		return;
	bekNode = (*bekList)->next;
	while (bekNode)
	{
		while ((bekNode->prev) && (bekNode->prev->n > bekNode->n))
		{
			bekNode = swap_node(bekNode, bekList);
			print_list(*bekList);
		}
		bekNode = bekNode->next;
	}
}
/**
 *swap_node - swap a node for his previous one
 *@bekNode: node
 *@bekList: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swap_node(listint_t *bekNode, listint_t **bekList)
{
	listint_t *back = bekNode->prev, *current = bekNode;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*bekList = current;
	return (current);
}
