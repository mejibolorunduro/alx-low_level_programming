#include "lists.h"

/**
 * free_listint - function that frees a listint_t list
 * @head: pointer to
 */
void free_listint(listint_t *head)
{
	listint_t *end;

	while (head != NULL)
	{
		end = head->next;
		free(head);
		head = end;
	}
}
