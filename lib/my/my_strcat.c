/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** concatenate two strings
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
	int lenght_of_dest = my_strlen(dest);
	int total_lenght = my_strlen(dest) + my_strlen(src);
	int count = 0;
	char *new_dest = malloc(sizeof(char) * (total_lenght + 1));

	while (count != lenght_of_dest) {
		new_dest[count] = dest[count];
		count = count + 1;
	}
	count = 0;
	while (count != total_lenght) {
		new_dest[lenght_of_dest + count] = src[count];
		count = count + 1;
	}
	return (new_dest);
}
