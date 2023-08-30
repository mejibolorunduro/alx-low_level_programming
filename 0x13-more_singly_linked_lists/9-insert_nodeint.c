#include "lists.h"

/**
 * insert_nodeint_at_index -  function that inserts a
 * new node at a given position
 * @head: apointer to a pointer
 * @idx: index of list where node is to be added
 * @n: integer
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int q;
	listint_t *new_node;
	listint_t *end = *head;

	new_node = malloc(sizeof(listint_t));
	if (!new_node || !head)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	for (q = 0; end && q < idx; q++)
	{
		if (q == idx - 1)
		{
			new_node->next = end->next;
			end->next = new_node;
			return (new_node);
		}
		else
			end = end->next;
	}

	return (NULL);
}
