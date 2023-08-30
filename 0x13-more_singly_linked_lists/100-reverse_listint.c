#include "lists.h"

/**
 * reverse_listint -  function that reverses a listint_t
 * @head: a pointer to a pointer
 *
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prv = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prv;
		prv = *head;
		*head = next;
	}

	*head = prv;

	return (*head);
}
