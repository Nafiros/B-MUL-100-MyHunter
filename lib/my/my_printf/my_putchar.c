/*
** EPITECH PROJECT, 2017
** putchar
** File description:
** putchar
*/

#include <stdarg.h>
#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}
