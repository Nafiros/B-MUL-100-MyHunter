/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** set textures of sprite
*/

#include "my.h"

void set_texture(struct ev evs, sfRenderWindow *window, sfMusic *game)
{
	sfVector2f origin = { 55, 55 };
	sfVector2f pos = { 0, -40 };

	sfSprite_setOrigin(evs.duck, origin);
	sfSprite_setPosition(evs.duck, origin);
	sfSprite_setTexture(evs.background, evs.bg, sfTrue);
	sfSprite_setTexture(evs.duck, evs.dk, sfTrue);
	sfSprite_setTexture(evs.crosshair, evs.ch, sfTrue);
	sfSprite_setTexture(evs.ps, evs.pause, sfTrue);
	sfSprite_setTexture(evs.sc, evs.scor, sfTrue);
	sfSprite_setTexture(evs.heart1, evs.hrt, sfTrue);
	sfSprite_setTexture(evs.heart2, evs.hrt, sfTrue);
	sfSprite_setPosition(evs.heart2, pos);
	sfRenderWindow_setMouseCursorVisible(window, sfFalse);
	sfRenderWindow_setFramerateLimit(window, 60);
	sfMusic_play(game);
}
