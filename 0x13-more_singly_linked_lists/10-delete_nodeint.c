#include "lists.h"

/**
 * delete_nodeint_at_index - function that deletes the node at index
 * @head: a pointer to a pointer
 * @index: index of the node to be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *end = *head;
	listint_t *curnt = NULL;
	unsigned int q = 0;

	if (*head == NULL)
	{
		return (-1);
	}

	if (index == 0)
	{
		*head = (*head)->next;
		free(end);
		return (1);
	}

	while (q < index - 1)
	{
		if (!end || !(end->next))
			return (-1);
		end = end->next;
		q++;
	}


	curnt = end->next;
	end->next = curnt->next;
	free(curnt);

	return (1);
}
