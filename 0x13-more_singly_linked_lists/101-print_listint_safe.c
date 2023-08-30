#include "lists.h"

/**
 * looped_listint_len -  function that prints a listint_t linked list
 * @head: a pointer to a pointer
 *
 * Return: the number of nodes in the list
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *trt, *hre;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	trt = head->next;
	hre = (head->next)->next;

	while (hre)
	{
		if (trt == hre)
		{
			trt = head;
			while (trt != hre)
			{
				nodes++;
				trt = trt->next;
				hre = hre->next;
			}

			trt = trt->next;
			while (trt != hre)
			{
				nodes++;
				trt = trt->next;
			}

			return (nodes);
		}

		trt = trt->next;
		hre = (hre->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - print lists with a loop
 * @head: A pointer to a pointer
 *
 * Return: number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, index = 0;

	nodes = looped_listint_len(head);

	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (index = 0; index < nodes; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodes);
}
