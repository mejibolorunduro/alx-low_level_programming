#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - This program will assign a random number to the variable n
 * Return: 0 (Success)
 */
int main(void)
{
	int n, papi;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	papi = n % 10;

	if (papi > 5)
	{
		printf("last digit of %d is %d is greater than 5\n", n, papi);
	}
	else if (papi == 0)
	{
		printf("last digit of %d is %d and is 0\n", n, papi);
	}
	else if (papi < 6 && papi != 0)
	{
		printf("last digit of %d is %d and is less than 6 and not 0\n", n, papi);
	}
	return (0);
}
