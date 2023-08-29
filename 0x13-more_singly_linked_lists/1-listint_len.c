#include "lists.h"

/**
 * listint_len - function that returns the number of elements
 * in a linked listint_t list
 *
 * @h: linked list
 *
 * Return: number of nodes
 */

size_t listint_len(const listint_t *h)
{
	size_t res = 0;

	while (h != NULL)
	{
		h = h->next;
		res++;
	}
	return (res);
}
