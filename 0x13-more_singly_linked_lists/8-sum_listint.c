#include "lists.h"

/**
 * sum_listint - function that returns the sum of all the data (n)
 * @head: a pointer to a pointer
 *
 * Return: 0 if the list is empty
 */
int sum_listint(listint_t *head)
{
	int val = 0;
	listint_t *end = head;

	while (end != NULL)
	{
		val += end->n;
		end = end->next;
	}

	return (val);
}
