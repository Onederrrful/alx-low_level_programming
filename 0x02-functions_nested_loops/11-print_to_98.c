#include <stdio.h>
#include "main.h"

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: the input
 */

void print_to_98(int n)
{
	int x = 98;

	if (n >= x)
	{
		while (n > x)
			printf("%d, ", n--);
		printf("%d\n", n);
	}
	else
	{
		while (n < x)
			printf("%d, ", n++);
		printf("%d\n", n);
	}

}
