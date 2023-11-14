#include "main.h"

/**
 * print_HEX - Prints an uppercase hexadecimal number.
 * @args: The va_list of arguments.
 *
 * Return: The number of characters printed (excluding null byte).
 */

int print_HEX(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;

	count += print_number_hex(n, 1);

	return (count);
}
