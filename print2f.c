#include "main.h"
#include <limits.h>

/**
 * print_int - imprime un entier sur sortie standard
 * @args: liste arguments contenat entier a imprimer
 * Return: nombre de chiffe a imprimer
 */

int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num;

	if (n == 0)
		return (_putchar('0'));

	if (n < 0)
	{
		count += _putchar('-');
		num = (unsigned int)(-n);
	}
	else
	{
		num = (unsigned int)n;
	}

	count += print_number(num);

	return (count);
}

int print_number(unsigned int num)
{
	int count = 0;
	unsigned int divisor = 1;

	while (num / divisor > 9)
		divisor *= 10;

	while (divisor != 0)
	{
		count += _putchar('0' + num / divisor);
		num %= divisor;
		divisor /= 10;
	}

	return (count);
}
