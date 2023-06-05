#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @g: linked list of type listint_t to print
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *g)
{
	size_t num = 0;

	while (g)
	{
		printf("%d\n", g->n);
		num++;
		g = g->next;
	}

	return (num);
}
