#include "lists.h"

/**
 * get_nodeint_at_index - function that returns the
 * nth node of a listint_t linked list
 * @head: a pointer to a pointer
 * @index: index of the node starting at 0
 *
 * Return:NULL if the node doesn't exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int q = 0;
	listint_t *end = head;

	while (end && q < index)
	{
		end = end->next;
		q++;
	}

	return (end ? end : NULL);
}
