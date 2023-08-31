#include "main.h"

/**
 * binary_to_uint -  function that converts a binary number
 * @b: a pointer
 *
 * Return: the converted number, or 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int z = 0;

	if (b == NULL)
	{
		return (0);
	}
	while (b[z])
	{
		if (b[z] != '0' && b[z] != '1')
		{
			return (0);
		}
		num = num * 2 + (b[z] - '0');
		z++;
	}
	return (num);
}
