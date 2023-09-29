#include "main.h"

/**
 * flip_bits - a function that counts the number of bits to change
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int q, c_count = 0;
	unsigned long int cur;
	unsigned long int excl = n ^ m;

	for (q = 63; q >= 0; q--)
	{
		cur = excl >> q;
		if (cur & 1)
		{
			c_count++;
		}
	}

	return (c_count);
}
