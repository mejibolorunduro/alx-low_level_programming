#include "main.h"

/**
 * print_binary - a function that prints the binary
 * equivalent of a decimal number
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	int q, c_count = 0;
	unsigned long int cur;

	for (q = 63; q >= 0; q--)
	{
		cur = n >> q;

		if (cur & 1)
		{
			_putchar('1');
			c_count++;
		}
		else if (c_count)
			_putchar('0');
	}
	if (!c_count)
	{
		_putchar('0');
	}
}
