#include "main.h"

/**
 * main - Entry point
 * Description: 'prints 10 times the alphabet, in lowercase'
 * followed by a new line
 */
void print_alphabet_x10/*prints 100 times the alphabet*/(void)
{
	char ch;
	int i;

	i = 0;

	while (i < 10)
	{
		ch = 'a';
		while (ch <= 'z')
		{
			_putchar(ch);
			ch++;
		}
		_putchar('\n');
		i++;
	}
}
