/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** render function
*/

#include "my.h"

void render_window(sfRenderWindow *wi, struct ev evs)
{
	sfRenderWindow_clear(wi, sfBlack);
	sfRenderWindow_drawSprite(wi, evs.background, NULL);
	sfRenderWindow_drawSprite(wi, evs.duck, NULL);
	sfRenderWindow_drawSprite(wi, evs.sc, NULL);
	sfRenderWindow_drawSprite(wi, evs.crosshair, NULL);
	sfRenderWindow_drawText(wi, evs.great, NULL);
	if (evs.missed == 0) {
		sfRenderWindow_drawSprite(wi, evs.heart1, NULL);
		sfRenderWindow_drawSprite(wi, evs.heart2, NULL);
	} else if (evs.missed == 1)
		sfRenderWindow_drawSprite(wi, evs.heart1, NULL);
	sfRenderWindow_display(wi);
}
