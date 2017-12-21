/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** destroy function
*/

#include "my.h"

void destroy(struct ev evs, sfRenderWindow *window)
{
	sfSprite_destroy(evs.duck);
	sfSprite_destroy(evs.background);
	sfTexture_destroy(evs.bg);
	sfSprite_destroy(evs.crosshair);
	sfTexture_destroy(evs.dk);
	sfTexture_destroy(evs.ch);
	sfTexture_destroy(evs.scor);
	sfSprite_destroy(evs.sc);
	sfMusic_destroy(evs.game);
	sfRenderWindow_destroy(window);
}
