#include "main.h"

/*
 * main - Entry point
 * Description: 'print_alphabet - print all alphabet in lowercase'
 */

void print_alphabet/*print all in lowercase*/(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
		_putchar(letter);

	_putchar('\n');
}
