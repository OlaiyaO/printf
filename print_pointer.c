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
	int i;

	if (p == NULL)
	{
		return (write(1, "(nil)", 5));
	}
	else
	{
		unsigned long int address = (unsigned long int)p;

		int count = write(1, "0x", 2);

		int digits = 0;
		unsigned long int temp = address;

		while (temp != 0)
		{
			temp /= 16;
			digits++;
		}

		for (i = digits - 1; i >= 0; i--)
		{
			int digit = (address >> (4 * i)) & 0xF;
			char hex_digit = (digit < 10) ? digit + '0' : digit - 10 + 'a';

			count += write(1, &hex_digit, 1);
		}

		return (count);
	}
}
