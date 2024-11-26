#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_string(char *s);
int print_percent(void);
int print_int(int n);
int handle_format(const char specifier, va_list args);

#endif /* MAIN_H */
