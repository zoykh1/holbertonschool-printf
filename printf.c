#include "main.h"

/**
 * _printf - Fonction printf personnalisée pour gérer
 *           les spécificateurs de format spécifiques.
 * @format: La chaîne contenant les caractères et spécificateurs.
 * @...: Les valeurs à formater et à imprimer.
 * Return: Nombre de caractères imprimés.
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
 * handle_specifier - Traite le spécificateur de format
 *                    et appelle la fonction appropriée.
 * @specifier: Le caractère spécificateur de format.
 * @args: Liste d'arguments.
 * @specifiers: Tableau des spécificateurs.
 * Return: Nombre de caractères imprimés pour le spécificateur.
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
