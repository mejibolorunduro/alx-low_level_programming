#include "main.h"

/**
 * get_endianness - a function that checks if a machine
 * is little or big endian
 * Return: 0,1 for big and little endian respectively
 */
int get_endianness(void)
{
	unsigned int q = 1;
	char *c = (char *) &q;

	return (*c);
}
