#include "main.h"

/**
 * print_pointer - Handles %p specifier (print pointer address).
 * @val: Variable arguments list
 *
 * Return: Number of characters printed (excluding null byte)
 */

int print_pointer(va_list val)
{
	void *p = va_arg(val, void*);
	char *nil_str = "(nil)";
	int count;

	if (p == NULL)
	{
		int i;

		for (i = 0; nil_str[i] != '\0'; i++)
		{
			_putchar(nil_str[i]);
		}
		return (i);
	}

	_putchar('0');
	_putchar('x');

	count = print_number_hex((unsigned long int)p, 0);

	return (count + 2);
}
