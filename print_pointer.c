#include "main.h"

/**
 * print_pointer - Handles %p specifier (print pointer address).
 * @args: Variable arguments list
 *
 * Return: Number of characters printed (excluding null byte)
 */

int print_pointer(va_list args)
{
	void *ptr = va_arg(args, void *);
	int count = 0;

	if (ptr == NULL)
	{
		count += write(1, "(nil)", 5);
	}
	else
	{
		count += _putchar('0');
		count += _putchar('x');
		count += print_number_hex((unsigned long)ptr, 0);
	}

	return (count);
}
