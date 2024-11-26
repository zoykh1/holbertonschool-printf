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

	va_starts(args, format);
	for (p = format; *p != '\0'; p++)
	{
		if (*p == '%')
		{
			p++;
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
 * handle_format - traite le specificateur de format et apelle la foction approprier
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
		return (print_string(va_arg(args, char *)));
	}
	else if (specifier == '%')
	{
		return (print_percent());
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		return (print_int(va_arg(args, int)));
	}
	return (_putchar(specifier));
}

/**
 * _putchar - ecrit un caractere sur la sortie standard
 * @c: caractere a imprimer
 * Return: toujours 1 (succes)
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - imprime une chaine sur la sortie standard
 * @s: chaine a imprimer
 * Return: nombre de caractere a imprimer
 */

int print_string(char *s)
{
	int count = 0;

	while (*s)
	{
		count += _putchar(s++);
	}
	return (count);
}

/**
 * print_percent - imprime %
 * Return: toujours 1 (succes)
 */

int print_percent(void)
{
	return (_putchar('%'));
}

/**
 * print_int - imprime un entier sur sortie standard
 * @n: entier a imprimer
 * Return: nombre de chiffe a imprimer
 */

int print_int(int n)
{
	int count = 0;

	if (n < 0)
	{
		count += _putchar('_');
		n = -n;
	}
	if (n / 10)
		count += print_int(n / 10);

	return (count + _putchar(n % 10 + '0'));
}
