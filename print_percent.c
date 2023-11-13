#include "main.h"

/**
 * print_percent - Handles %% specifier
 * @args: Variable arguments list
 *
 * Return: Number of characters printed (excluding null byte)
 */

int print_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}
