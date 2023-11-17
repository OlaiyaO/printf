#include "main.h"

/**
 * print_pointer - Handles %p specifier (print pointer address).
 * @args: Variable arguments list
 *
 * Return: Number of characters printed (excluding null byte)
 */

int print_pointer(va_list args)
{
	void *p = va_arg(args, void*);
	char *nil_str = "(nil)";
	int count = 0, i;

	if (p == NULL)
	{
		for (i = 0; nil_str[i] != '\0'; i++)
		{
			_putchar(nil_str[i]);
			count++;
		}
	}
	else
	{
		count += _putchar('0');
		count += _putchar('x');
		count += print_number_hex((unsigned long int)p, 0);
	}

	return (count);
}
