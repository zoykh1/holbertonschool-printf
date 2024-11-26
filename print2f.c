#include "main.h"

/**
 * print_string - imprime une chaine sur la sortie standard
 * @s: chaine a imprimer
 * Return: nombre de caractere a imprimer
 */

int print_string(char *s)
{
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
