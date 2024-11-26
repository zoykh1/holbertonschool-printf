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
	for (p = format; *p != '\0'; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '\0')
				break;
			count += handle_format(*p, args);
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
 * handle_format - traite le specificateur de format et
 *					apelle la foction approprier
 * @specifier: le caractere specificateur de format
 * @args: liste d'arguments
 * Return: nombre de caractere imprimer pour le specificateur
 */

int handle_format(const char specifier, va_list args)
{
	if (specifier == 'c')
	{
		return (_putchar(va_arg(args, int)));
	}
	else if (specifier == 's')
	{
		char *str = va_arg(args, char *);

		return (print_string(str ? str : "(null)"));
	}
	else if (specifier == '%')
	{
		return (print_percent());
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		return (print_int(va_arg(args, int)));
	}
	return (_putchar('%') + _putchar(specifier));
}
