/*
** EPITECH PROJECT, 2017
** my_put_nbr_base
** File description:
** putnbrbase
*/

#include <stdarg.h>

void my_putchar(char);
int my_strlen(char *);

int my_putnbr_base(int nbr, char *base)
{
	int len = my_strlen(base);

	if (nbr < 0) {
		nbr = nbr * -1;
		my_putchar('-');
	} else if (nbr == 0)
		return (0);
	else
		my_putnbr_base(nbr / len, base);
	my_putchar(base[nbr % len]);
}

int my_putnbr_base_unsigned(unsigned long int nbr, char *base)
{
	unsigned long int len = my_strlen(base);

	if (nbr < 0) {
		nbr = nbr * -1;
		my_putchar('-');
	} else if (nbr == 0)
		return (0);
	else
		my_putnbr_base_unsigned(nbr / len, base);
	my_putchar(base[nbr % len]);
}
