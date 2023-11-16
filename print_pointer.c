#include "main.h"

/**
 * print_pointer - Handles %p specifier (print pointer).
 * @args: Variable arguments list
 *
 * Return: Number of characters printed (excluding null byte)
 */

int print_pointer(va_list args)
{
	void *ptr = va_arg(args, void *);
	int count = 0;

	_putchar('0');
	_putchar('x');
	count += 2;

	if (ptr == NULL)
	{
		_putchar('0');
		count++;
	}
	else
	{
		count += print_number_hex((unsigned long)ptr, 0);
	}

	return (count);
}
