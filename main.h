#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct format_specifier - structure pour gerer specificateur de formats
 * @specifier: caractere du specificateur
 * @func: pointeur vers la fonction qui gere le specificateur
 */

typedef struct format_specifier
{
	char specifier;
	int (*func)(va_list);
} format_specifier_t;

int _printf(const char *format, ...);
int _putchar(char c);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_number(int num);
int print_int(va_list args);
int handle_specifier(const char specifier, va_list args, format_specifier_t
specifiers[]);

#endif /* MAIN_H */
