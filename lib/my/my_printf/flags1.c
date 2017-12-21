/*
** EPITECH PROJECT, 2017
** all fonctions for flags used by printf
** File description:
** flag
*/

#include <stdarg.h>

void my_putchar(char);
int my_putnbr_base(int, char*);
void my_putstr(char *);

void f_b(va_list args)
{
	int nbr = va_arg(args, int);

	my_putnbr_base(nbr, "01");
}

void f_o(va_list args)
{
	int nbr = va_arg(args, int);

	my_putnbr_base(nbr, "01234567");
}

void f_x(va_list args)
{
	int nbr = va_arg(args, int);

	my_putnbr_base(nbr, "0123456789abcdef");
}

void f_xu(va_list args)
{
	int nbr = va_arg(args, int);

	my_putnbr_base(nbr, "0123456789ABCDEF");
}

void f_s(va_list args)
{
	char *str = va_arg(args, char *);

	my_putstr(str);
}
