#include "lists.h"

/**
 * free_listint_safe - function that frees a listint_t list
 * @h: pointer to the first node
 *
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	size_t tem = 0;
	int opp;
	listint_t *end;

	if (!h || !*h)
	{
		return (0);
	}

	while (*h)
	{
		opp = *h - (*h)->next;
		if (opp > 0)
		{
			end = (*h)->next;
			free(*h);
			*h = end;
			tem++;
		}
		else
		{
			free(*h);
			*h = NULL;
			tem++;
			break;
		}
	}

	*h = NULL;

	return (tem);
}
