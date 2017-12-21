/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** put nbr
*/

#include <stdarg.h>

int my_putchar(char);

void	my_put_nbr(int nb)
{
	int nbr;

	if (nb < 0) {
		my_putchar(45);
		nb = nb * -1;
	}
	if (nb >= 0) {
		if (nb >= 10) {
			nbr = nb % 10;
			nb = nb - nbr;
			nb = nb / 10;
			my_put_nbr(nb);
			my_putchar(nbr + 48);
		} else
			my_putchar(nb + 48);
	}
}

void    my_putnbr_unsigned(unsigned long int nb)
{
	unsigned long int nbr;

	if (nb < 0) {
		my_putchar(45);
		nb = nb * -1;
	}
	if (nb >= 0) {
		if (nb >= 10) {
			nbr = nb % 10;
			nb = nb - nbr;
			nb = nb / 10;
			my_putnbr_unsigned(nb);
			my_putchar(nbr + 48);
		} else
			my_putchar(nb + 48);
	}
}
