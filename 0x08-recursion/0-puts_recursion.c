#include <stdio.h>
/**
 * puts_recursion - a function that prints a string
 * @s - string input
 *
 * Return - printed string
 */
void _puts_recursion(char *s)
{
    if (*s == '\0')
    {
        return;
    }
    printf("%c", *s);
    _puts_recursion(s + 1);
}
