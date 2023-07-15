#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - This program will assign a random number to the variable
 * Return: return 0 (Success)
 */
int main(void)
{
	int n;

	int p;
	/* nothing is here */
	srand(time(0));
	n = rand() - RAND_MAX / 2;
	p = n % 10;
	if (p > 5)
	{
		printf("last digit of %d is %d and is greater than 5\n", 98, p);
	}
	else if (p == 0)
	{
		printf("last digit of %d is %d and is 0\n", -98, p);
	}
	else
	{
		printf("last digit of %d is %d and is less than 6 and not 0\n", 980, p);
	}
	return (0);
}
