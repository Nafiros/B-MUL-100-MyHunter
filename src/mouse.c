/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** mouse cursor movement
*/

#include "my.h"

void mouse_cursor(struct ev evs, sfRenderWindow *window)
{
	sfVector2i mouse_pos_x_y;
	sfVector2f mouse_position;

	mouse_pos_x_y = sfMouse_getPositionRenderWindow(window);
	mouse_position.x = (float)mouse_pos_x_y.x - (55 / 2);
	mouse_position.y = (float)mouse_pos_x_y.y - (55 / 2);
	sfSprite_setPosition(evs.crosshair, mouse_position);
}
