/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** function my_printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../../../include/my.h"

int which_function(int i, int index, char const *format, va_list args)
{
	char *selector = "dioscbxXpu";
	void (*fct_list[10])(va_list) = { f_d, f_d, f_o, f_s, f_c, f_b,
	f_x, f_xu, f_p, f_u };

	while (selector[index] != '\0') {
		if (format[i + 1] == selector[index]) {
			(*fct_list[index])(args);
			index = 0;
			i = i + 2;
			return (i);
		} else if (format[i + 1] == '%') {
			my_putchar('%');
			i = i + 2;
			return (i);
		} else
			index++;
	}
	return (i + 2);
}

int my_printf(char const *format, ...)
{
	va_list args;
	int i = 0;
	int index = 0;

	va_start(args, format);
	while (format[i] != '\0') {
		if (format[i] == '%') {
			i = which_function(i, index, format, args);
		} else {
			my_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (0);
}
