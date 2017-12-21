/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** event 
*/

#include "my.h"

struct ev event_sc(sfRenderWindow *w, sfEvent *e, struct ev evs)
{
	if (e->type == sfEvtClosed)
		sfRenderWindow_close(w);
	if (e->type == sfEvtMouseButtonPressed) {
		if ((evs.mouse_pos.x + 55 >= evs.duck_pos.x)
		&& (evs.mouse_pos.x <= evs.duck_pos.x + 55)
		&& (evs.mouse_pos.y + 55 >= evs.duck_pos.y)
		&& (evs.mouse_pos.y <= evs.duck_pos.y + 55)) {
			evs.score += 1;
			my_printf("Well done !\nScore %d\n", evs.score);
			sfText_setString(evs.great, my_set_nbr(evs.score));
			evs.duck_pos.x = -110;
			evs.duck_pos.y = rand_nbr(100, 500);
			sfSprite_setPosition(evs.duck, evs.duck_pos);
			evs.speed += 1;
		} else {
			evs.missed += 1;
			my_printf("Too bad !\nMissed %d\n", evs.missed);
		}
	}
	is_pause(evs, w, e);
	return (evs);
}

int event2(sfRenderWindow *window, sfEvent *e, struct ev evs)
{
	sfVector2i mouse_pos;

	mouse_pos = sfMouse_getPositionRenderWindow(window);
	if (e->type == sfEvtClosed) {
		sfRenderWindow_close(window);
		return (1);
	}
	if (e->type == sfEvtMouseButtonPressed) {
		if ((mouse_pos.x >= 129) && (mouse_pos.x <= 427)
		&& (mouse_pos.y >= 387) && (mouse_pos.y <= 423)) {
			sfRenderWindow_close(window);
			return (0);
		}
		if ((mouse_pos.x >= 4) && (mouse_pos.x <= 53)
		&& (mouse_pos.y >= 721) && (mouse_pos.y <= 764)) {
			sfRenderWindow_close(window);
			return (1);
		}
		if ((mouse_pos.x >= 501) && (mouse_pos.x <= 549)
		&& (mouse_pos.y >= 717) && (mouse_pos.y <= 766)) {
			sfRenderWindow_drawSprite(window, evs.credit_menu, NULL);			return (2);
		}
	}
}

void hover(sfRenderWindow *window, struct ev evs)
{
	sfVector2i mouse_pos;

	mouse_pos = sfMouse_getPositionRenderWindow(window);
	if ((mouse_pos.x >= 129) && (mouse_pos.x <= 427)
	&& (mouse_pos.y >= 387) && (mouse_pos.y <= 423)) {
		sfSprite_setTexture(evs.play_button, evs.play_h, sfTrue);
	} else
		sfSprite_setTexture(evs.play_button, evs.play, sfTrue);
	if ((mouse_pos.x >= 4) && (mouse_pos.x <= 53)
	&& (mouse_pos.y >= 721) && (mouse_pos.y <= 764)) {
		sfSprite_setTexture(evs.quit_button, evs.quit_h, sfTrue);
	} else
		sfSprite_setTexture(evs.quit_button, evs.quit, sfTrue);
	if ((mouse_pos.x >= 501) && (mouse_pos.x <= 549)
	&& (mouse_pos.y >= 717) && (mouse_pos.y <= 766)) {
		sfSprite_setTexture(evs.credit_button, evs.credit_h, sfTrue);
	} else
		sfSprite_setTexture(evs.credit_button, evs.credit, sfTrue);
}
