#include "main.h"

/**
 * print_hex - Prints a lowercase hexadecimal number.
 * @args: The va_list of arguments.
 *
 * Return: The number of characters printed (excluding null byte).
 */

int print_hex(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;

	count += print_number_hex(n, 0);

	return (count);
}
