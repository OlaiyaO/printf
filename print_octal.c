#include "main.h"

/**
 * print_octal - Prints an octal number.
 * @args: The va_list of arguments.
 *
 * Return: The number of characters printed (excluding null byte).
 */
int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;

	count += print_number(n, 8);

	return (count);
}
