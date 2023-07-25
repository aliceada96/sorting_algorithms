#include "sort.h"

/**
 * swap_node - Swaps two nodes in a listint_t doubly-linked list.
 * @head: A ptr to the head of list.
 * @node1: A ptr to the first node to swap.
 * @node2: ptr to second node to swap.
 */
void swap_node(listint_t **head, listint_t **node1, listint_t *node2)
{
    (*node1)->next = node2->next;
    if (node2->next != NULL)
        node2->next->prev = *node1;
    node2->prev = (*node1)->prev;
    node2->next = *node1;
    if ((*node1)->prev != NULL)
        (*node1)->prev->next = node2;
    else
        *head = node2;
    (*node1)->prev = node2;
    *node1 = node2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of ints in ascending order
 * @list: list of nodes being swapped
 *
 * Description: dont modify the integer n of a node. You have to swap the nodes themselves
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *i, *new, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (i = (*list)->next; i != NULL; i = temp)
    {
        temp = i->next;
        new = i->prev;
        while (new != NULL && i->n < new->n)
        {
            swap_node(list, &new, i);
            print_list((const listint_t *)*list);
        }
    }
}
