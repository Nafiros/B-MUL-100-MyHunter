/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** random nbr
*/

#include "my.h"

int rand_nbr(int min, int max)
{
	return (rand() % (max - min) + min);
}
