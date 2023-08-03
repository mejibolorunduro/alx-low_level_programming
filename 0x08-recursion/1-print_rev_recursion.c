#include <stdio.h>

/**
 * print_rev_recursion.c - function that prints a string in reverse
 * @s - string to be printed in reverse
 *
 * Return - printed srting in reverse
 */
void _print_rev_recursion(char *s)
{
    if (*s == '\0')
    {
        return;
    }
    _print_rev_recursion(s + 1);
    printf("%c", *s);
}
