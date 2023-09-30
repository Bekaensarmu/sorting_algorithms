#include "sort.h"

void swap_node_ahead(listint_t **len_list, listint_t **len_tail, listint_t **len_shaker);
void swap_node_behind(listint_t **len_list, listint_t **len_tail, listint_t **len_shaker);
void cocktail_sort_list(listint_t **len_list);

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @len_list: A pointer to the head of a doubly-linked list of integers.
 * @len_tail: A pointer to the tail of the doubly-linked list.
 * @len_shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **len_list, listint_t **len_tail, listint_t **len_shaker)
{
    listint_t *tmp = (*len_shaker)->next;

    if ((*len_shaker)->prev != NULL)
        (*len_shaker)->prev->next = tmp;
    else
        *len_list = tmp;
    tmp->prev = (*len_shaker)->prev;
    (*len_shaker)->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = *len_shaker;
    else
        *len_tail = *len_shaker;
    (*len_shaker)->prev = tmp;
    tmp->next = *len_shaker;
    *len_shaker = tmp;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @len_list: A pointer to the head of a doubly-linked list of integers.
 * @len_tail: A pointer to the tail of the doubly-linked list.
 * @len_shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **len_list, listint_t **len_tail, listint_t **len_shaker)
{
    listint_t *tmp = (*len_shaker)->prev;

    if ((*len_shaker)->next != NULL)
        (*len_shaker)->next->prev = tmp;
    else
        *len_tail = tmp;
    tmp->next = (*len_shaker)->next;
    (*len_shaker)->prev = tmp->prev;
    if (tmp->prev != NULL)
        tmp->prev->next = *len_shaker;
    else
        *len_list = *len_shaker;
    (*len_shaker)->next = tmp;
    tmp->prev = *len_shaker;
    *len_shaker = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @len_list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **len_list)
{
    listint_t *len_tail, *len_shaker;
    bool shaken_not_stirred = false;

    if (len_list == NULL || *len_list == NULL || (*len_list)->next == NULL)
        return;

    for (len_tail = *len_list; len_tail->next != NULL;)
        len_tail = len_tail->next;

    while (shaken_not_stirred == false)
    {
        shaken_not_stirred = true;
        for (len_shaker = *len_list; len_shaker != len_tail; len_shaker = len_shaker->next)
        {
            if (len_shaker->n > len_shaker->next->n)
            {
                swap_node_ahead(len_list, &len_tail, &len_shaker);
                print_list((const listint_t *)*len_list);
                shaken_not_stirred = false;
            }
        }
        for (len_shaker = len_shaker->prev; len_shaker != *len_list; len_shaker = len_shaker->prev)
        {
            if (len_shaker->n < len_shaker->prev->n)
            {
                swap_node_behind(len_list, &len_tail, &len_shaker);
                print_list((const listint_t *)*len_list);
                shaken_not_stirred = false;
            }
        }
    }
}
