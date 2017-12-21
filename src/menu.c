/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** menu
*/

#include "my.h"

struct ev init_texture(struct ev evs)
{
	evs.menu = sfTexture_createFromFile("./assets/menu/menu.png", NULL);
	evs.play = sfTexture_createFromFile("./assets/menu/play.png", NULL);
	evs.play_h = sfTexture_createFromFile("./assets/menu/play_h.png", NULL);
	evs.quit = sfTexture_createFromFile("./assets/menu/quit.png", NULL);
	evs.quit_h = sfTexture_createFromFile("./assets/menu/quit_h.png", NULL);
	evs.credit = sfTexture_createFromFile("./assets/menu/credit.png", NULL);
	evs.credit_h = sfTexture_createFromFile("./assets/menu/credit_h.png", NULL);
	evs.credit_m = sfTexture_createFromFile("./assets/menu/credit_m.png", NULL);
	evs.m = sfSprite_create();
	evs.play_button = sfSprite_create();
	evs.quit_button = sfSprite_create();
	evs.credit_button = sfSprite_create();
	evs.credit_menu = sfSprite_create();
	sfSprite_setTexture(evs.m, evs.menu, sfTrue);
	sfSprite_setTexture(evs.play_button, evs.play, sfTrue);
	sfSprite_setTexture(evs.quit_button, evs.quit, sfTrue);
	sfSprite_setTexture(evs.credit_button, evs.credit, sfTrue);
	sfSprite_setTexture(evs.credit_menu, evs.credit_m, sfTrue);
	return (evs);
}

int render_credit(struct ev evs, sfRenderWindow *window, sfEvent *event)
{
	int continuer = 1;

	while (sfRenderWindow_pollEvent(window, event)) {
		if (event->type == sfEvtMouseButtonPressed) {
			continuer = 0;
			break;
		}
	}
	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_drawSprite(window, evs.credit_menu, NULL);
	sfRenderWindow_display(window);
	return (continuer);
}

void render_menu(struct ev evs, sfRenderWindow *window, int return_value)
{
	sfEvent event;
	int continuer = 1;

	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_drawSprite(window, evs.m, NULL);
	sfRenderWindow_drawSprite(window, evs.play_button, NULL);
	sfRenderWindow_drawSprite(window, evs.quit_button, NULL);
	sfRenderWindow_drawSprite(window, evs.credit_button, NULL);
	if (return_value == 2) {
		while (continuer == 1) {
			continuer = render_credit(evs, window, &event);
		}
	}
	sfRenderWindow_display(window);
}

void destroy_menu(struct ev evs, sfRenderWindow *window)
{
	sfSprite_destroy(evs.m);
	sfSprite_destroy(evs.play_button);
	sfSprite_destroy(evs.quit_button);
	sfSprite_destroy(evs.credit_button);
	sfRenderWindow_destroy(window);
}

int menu(sfRenderWindow *window, struct ev evs)
{
	sfEvent event;
	int return_value = 0;
	sfMusic *main = sfMusic_createFromFile("./assets/sound/main.wav");

	evs = init_texture(evs);
	window = sfRenderWindow_create(evs.mode2, "My_Hunter", sfClose, NULL);
	sfMusic_setLoop(main, sfTrue);
	sfMusic_play(main);
	sfRenderWindow_setFramerateLimit(window, 60);
	while (sfRenderWindow_isOpen(window)) {
		sfRenderWindow_clear(window, sfBlack);
		while (sfRenderWindow_pollEvent(window, &event))
			return_value = event2(window, &event, evs);
		hover(window, evs);
		render_menu(evs, window, return_value);
	}
	sfMusic_stop(main);
	sfMusic_destroy(main);
	destroy_menu(evs, window);
	return (return_value);
}
