#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer.
 * @args: The va_list of arguments.
 *
 * Return: The number of characters printed (excluding null byte).
 */

int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;

	count += print_number(n, 10);

	return (count);
}
