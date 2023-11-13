#include "main.h"

/**
 * print_str - Handles %s specifier
 * @args: Variable arguments list
 *
 * Return: Number of characters printed (excluding null byte)
 */

int print_str(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str != '\0')
	{
		_putchar(*str);
		count++;
		str++;
	}

	return (count);
}
