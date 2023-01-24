#include "main.h"

/**
 * _puts - a function that prints a string with newline
 * @str: the string to print
 *
 * Return: void
 */
int _puts(char *str)
{
	char *pt = str;

	while (*str)
		_putchar(*str++);
	return (str - pt);
}

/**
 * _putchar - a fucntion that writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	static int num;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || num >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, num);
		num = 0;
	}
	if (c != BUF_FLUSH)
		buf[num++] = c;
	return (1);
}
