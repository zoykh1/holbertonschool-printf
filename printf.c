#include "main.h"

/**
 * _printf - Custom printf function to handle specific format specifiers
 * @format: The string containing characters and specifiers
 * @...: The values to format and print
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	format_specifier_t specifiers[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'d', print_int}, {'i', print_int}, {'\0', NULL}
	};

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (format && *format)
	{
		if (*format != '%')
			count += _putchar(*format);
		else
		{
			if (*(format + 1) == '\0')
				return (-1);
			format++;
			count += handle_specifier(*format, args, specifiers);
		}
		format++;
	}
	va_end(args);
	return (count);
}

/**
 * handle_specifier - Handles format specifier and calls appropriate function
 * @specifier: The format specifier character
 * @args: List of arguments
 * @specifiers: Array of specifiers
 * Return: Number of characters printed for the specifier
 */
int handle_specifier(char specifier, va_list args, format_specifier_t specifiers[])
{
	int i;

	for (i = 0; specifiers[i].specifier != '\0'; i++)
	{
		if (specifiers[i].specifier == specifier)
			return (specifiers[i].func(args));
	}
	return (_putchar('%') + _putchar(specifier));
}
