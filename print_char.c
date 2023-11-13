#include "main.h"

/**
 * print_char - Handles %c specifier
 * @args: Variable arguments list
 *
 * Return: Number of characters printed (excluding null byte)
 */

int print_char(va_list args)
{
	int character = va_arg(args, int);

	_putchar(character);

	return (1);
}
