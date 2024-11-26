#include "main.h"

/**
 * _printf - fonction printf personnalisé pour gerer
 *			specificateur de formats specifiques
 * @format: la chaine de caractere conteant les caracteres et specificateurs
 * @...: les valeurs a formater et a imprimer
 * Return: nombre de caracteres a imprimer
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *p;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	format_specifier_t specifiers[] = {
		{'c', (int (*)(va_list))_putchar},
		{'s', (int (*)(va_list))print_string},
		{'%', (int (*)(va_list))print_percent},
		{'d', (int (*)(va_list))print_int},
		{'i', (int (*)(va_list))print_int},
		{'\0', NULL}
	};
	for (p = format; *p != '\0'; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '\0')
				break;
			count += handle_specifier(*p, args, specifiers);
		}
		else
		{
			count += _putchar(*p);
		}
	}
	va_end(args);
	return (count);
}


/**
 * handle_specifier - traite le specificateur de format et
 *					apelle la foction approprier
 * @specifier: le caractere specificateur de format
 * @args: liste d'arguments
 * @specifiers: tableau des specificateurs
 * Return: nombre de caractere imprimer pour le specificateur
 */

int handle_specifier(char specifier, va_list args, format_specifier_t
specifiers[])
{
	for (int i = 0; specifiers[i].specifier != '\0'; i++)
	{
		if (specifiers[i].specifier == specifier)
		{
			return (specifiers[i].func(args));
		}
	}
	return (_putchar('%') + _putchar(specifier));
}
