/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** moves functions
*/

#include "my.h"

int move_rect(sfIntRect *rect, sfSprite *sprite, int back_and_forth)
{
	sfSprite_setTextureRect(sprite, *rect);
	if ((back_and_forth == 0) && (rect->left < 220))
		rect->left += 110;
	else if ((back_and_forth == 0) && (rect->left == 220)) {
		rect->left -= 110;
		back_and_forth = 1;
	}
	if ((back_and_forth == 1) && (rect->left > 0))
		rect->left -= 110;
	else if ((back_and_forth == 1) && (rect->left == 0)) {
		rect->left += 110;
		back_and_forth = 0;
	}
	sfSprite_setTextureRect(sprite, *rect);
	return (back_and_forth);
}

int move_sprite(sfSprite *sprite, int back_and_forth, float speed)
{
	sfVector2f vector = { 5, 0 };
	sfVector2f vector_neg = { -5, 0 };
	sfVector2f position = sfSprite_getPosition(sprite);;
	sfVector2f scale_neg = { -1, 1 };
	sfVector2f scale = { 1, 1 };

	vector.x += speed;
	vector_neg.x -= speed;
	if ((back_and_forth == 0) && position.x < 1460) {
		sfSprite_move(sprite, vector);
	} else if ((back_and_forth == 0) && position.x >= 1460) {
		sfSprite_move(sprite, vector_neg);
		sfSprite_setScale(sprite, scale_neg);
		back_and_forth = 1;
	}
	if ((back_and_forth == 1) && position.x > -180) {
		sfSprite_move(sprite, vector_neg);
	} else if ((back_and_forth == 1) && position.x <= -180) {
		sfSprite_move(sprite, vector);
		sfSprite_setScale(sprite, scale);
		back_and_forth = 0;
	}
	return (back_and_forth);
}

sfIntRect set_rect(sfIntRect rect)
{
	rect.top = 0;
	rect.left = 0;
	rect.width = 110;
	rect.height = 110;
	return (rect);
}
