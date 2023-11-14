
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */

int _printf(const char *format, ...)
{
	FormatSpecifier specifiers[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
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
