/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** end of game
*/

#include "my.h"

int is_end(struct ev evs, sfRenderWindow *w)
{
	if (evs.missed == 2) {
		my_printf("Final Score: %d\n", evs.score);
		my_printf("Final Missed: %d\n", evs.missed);
		sfRenderWindow_close(w);
		return (1);
	}
	return (0);
}
