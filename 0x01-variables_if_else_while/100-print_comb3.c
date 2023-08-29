#include <stdio.h>
/**
 * main - Entry point
 * Description - 'prints all possible different combinations of two digits.'
 * Return: 0 (Success)
 */
int main(void)
{
	int i;
	int j;

	for (i = 0; i < 10; i++) 
	{
		putchar(i);
		if (i == 10)
	{
		continue;
	}
        for (j = 0; j < 10; j++) 
	{
		putchar(j);
		if (j == 10)
	{
		continue;
	}

            if (i < j)
	    {
                putchar(i + '0');
                putchar(j + '0');
                if (i != 9 || j != 8) 
		{
                    putchar(',');
                    putchar(' ');
		}
	    }
	}
	}
                return (0);
}
