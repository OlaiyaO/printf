#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

typedef struct FormatSpecifier
{
	char specifier;
	int (*handler)(va_list);
} FormatSpecifier;

int _printf(const char *format, ...);

int _putchar(char c);

int print_char(va_list args);

int print_str(va_list args);

int print_percent(va_list args);

#endif /* MAIN_H */
