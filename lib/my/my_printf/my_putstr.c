/*
** EPITECH PROJECT, 2017
** putstr
** File description:
** putstr
*/

#include <stdarg.h>

void my_putchar(char);

void    my_putstr(char const *str)
{
	int count = 0;

	while (str[count] != '\0') {
		my_putchar(str[count]);
		count++;
	}
}
