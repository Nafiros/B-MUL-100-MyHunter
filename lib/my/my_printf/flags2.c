/*
** EPITECH PROJECT, 2017
** flags / printf
** File description:
** 2nd part of function needed by printf
*/

#include <stdarg.h>

void my_put_nbr(int);
void my_putchar(char);
void my_put_ptr(void *);
void my_putnbr_unsigned(unsigned long int);

void f_d(va_list args)
{
	int nb = va_arg(args, int);

	my_put_nbr(nb);
}

void f_pe(va_list args)
{
	my_putchar('%');
}

void f_c(va_list args)
{
	int c = (char)va_arg(args, int);

	my_putchar(c);
}

void f_p(va_list args)
{
	void *p = va_arg(args, void *);

	my_put_ptr((void *)p);
}

void f_u(va_list args)
{
	unsigned long int nbr = va_arg(args, unsigned int);

	my_putnbr_unsigned(nbr);
}
