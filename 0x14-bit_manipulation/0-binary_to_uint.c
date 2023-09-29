#include "main.h"

/**
 * binary_to_uint - a function that converts a binary
 * number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int q;
	unsigned int value = 0;

	if (!b)
	{
		return (0);
	}

	for (q = 0; b[q]; q++)
	{
		if (b[q] < '0' || b[q] > '1')
		{
			return (0);
		}
		value = 2 * value + (b[q] - '0');
	}

	return (value);
}
