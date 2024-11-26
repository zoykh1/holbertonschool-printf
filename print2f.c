#include "main.h"

/**
 * print_string - imprime une chaine sur la sortie standard
 * @args: chaine a imprimer
 * Return: nombre de caractere a imprimer
 */

int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int count = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		count += _putchar(*s++);
	}

	return (count);
}


/**
 * print_percent - imprime %
 * @args: liste arguments
 * Return: toujours 1 (succes)
 */

int print_percent(va_list args)
{
	(void)args;
	return (_putchar('%'));
}

/**
 * print_int - imprime un entier sur sortie standard
 * @args: liste arguments contenat entier a imprimer
 * Return: nombre de chiffe a imprimer
 */

int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		n = -n;
	}
	count += print_number(n);

	return (count);
}


/**
 * print_number - imprime nombre en utilisant recursion
 * @num: nombre a imprimer
 * Return: nombre de chiffre a imprimer
 */

int print_number(int num)
{
	int count = 0;

	if (num / 10)
		count += print_number(num / 10);
	return (count + _putchar(num % 10 + '0'));
}
