#include "main.h"

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
		count += _putchar(*s++);
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
		count += _putchar('-');
		n = -n;
	}
	if (n / 10)
		count += print_int(n / 10);

	return (count + _putchar(n % 10 + '0'));
}
