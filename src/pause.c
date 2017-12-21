/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** pause
*/

#include "my.h"

int my_pause(sfEvent *event, sfRenderWindow *window, struct ev evs)
{
	int continuer = 1;

	while (sfRenderWindow_pollEvent(window, event)) {
		if (event->type == sfEvtKeyPressed
		&& sfKeyboard_isKeyPressed(sfKeyEscape)) {
			continuer = 0;
			break;
		}
	}
	sfRenderWindow_drawSprite(window, evs.ps, NULL);
	sfRenderWindow_display(window);
	return (continuer);
}

void is_pause(struct ev evs, sfRenderWindow *window, sfEvent *event)
{
	int continuer = 1;

	if (event->type == sfEvtKeyPressed
	&& sfKeyboard_isKeyPressed(sfKeyEscape)) {
		while (continuer == 1) {
			continuer = my_pause(event, window, evs);
		}
	}
}
