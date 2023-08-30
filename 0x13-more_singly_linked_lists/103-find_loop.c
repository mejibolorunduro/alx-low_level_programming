#include "lists.h"

/**
 * find_listint_loop - function that finds the loop in a linked list
 * @head: a pointer to a pointer
 *
 * Return: address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *lon = head;
	listint_t *spr = head;

	if (!head)
	{
		return (NULL);
	}

	while (lon && spr && spr->next)
	{
		spr = spr->next->next;
		lon = lon->next;
		if (spr == lon)
		{
			lon = head;
			while (lon != spr)
			{
				lon = lon->next;
				spr = spr->next;
			}
			return (spr);
		}
	}

	return (NULL);
}
