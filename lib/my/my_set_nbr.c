/*
** EPITECH PROJECT, 2017
** my_set_nbr
** File description:
** put an int int a string
*/

#include "my.h"

char *malloc_string(int nb, char *number)
{
	int digit = 1;

	if (nb < 0)
		digit++;
	while (nb >= 10) {
		nb = nb / 10;
		digit += 1;
	}
	number = malloc(sizeof(char) * digit + 1);
	return (number);
}

char *my_set_nbr(int nb)
{
	int nbr = nb;
	int numb = 1;
	char *number = malloc_string(nb, number);
	int i = 0;

	if (nb < 0) {
		number[i] = '-';
		i++;
		nbr = nb * -1;
	}
	while (numb <= nbr)
		numb *= 10;
	numb = numb / 10;
	while (numb) {
		number[i] = (nbr / numb) % 10 + '0';
		i++;
		numb = numb / 10;
	}
	number[i] = '\0';
	return (number);
}
