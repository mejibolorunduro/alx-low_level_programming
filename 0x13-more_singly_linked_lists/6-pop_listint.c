#include "lists.h"

/**
 * pop_listint - function that deletes the head node of a listint_t
 * @head: a pointer to a pointer
 *
 * Return: 0 if the linked list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *end;
	int res;

	if (!head || !*head)
	{
		return (0);
	}

	res = (*head)->n;
	end = (*head)->next;
	free(*head);
	*head = end;

	return (res);
}
