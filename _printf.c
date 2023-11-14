#include "main.h"

/**
 * _printf - Prints formatted text to stdout.
 * @format: The format string containing format specifiers.
 *          Supported specifiers: %c, %s, %%, %d, %i.
 *
 * Return: The number of characters printed (excluding null byte).
 */

int _printf(const char *format, ...)
{
	FormatSpecifier specifiers[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
		{'d', print_decimal},
		{'i', print_integer},
		{'\0', NULL}
	};
	int count = 0, i = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			while (specifiers[i].specifier != '\0')
			{
				if (*format == specifiers[i].specifier)
				{
					count += specifiers[i].handler(args);
					break;
				}
				i++;
			}
			if (specifiers[i].specifier == '\0')
				count += (write(1, "%", 1) + (format ? write(1, format, 1) : 0));
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
		i = 0;
	}
	va_end(args);
	return (count);
}
