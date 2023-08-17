#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - a function that returns the sum of all its parameters
 * @n: number of parameters
 * Return: n == 0, return 0
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int d, sum = 0;

	va_start(ap, n);

	for (d = 0; d < n; d++)
	{
		sum += va_arg(ap, int);
	}

	va_end(ap);
	return (sum);
}
