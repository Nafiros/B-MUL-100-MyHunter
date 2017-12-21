/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** main
*/

#include "my.h"

struct ev set_value(struct ev evs)
{
	evs.hrt = sfTexture_createFromFile("./assets/heart.png", NULL);
	evs.heart1 = sfSprite_create();
	evs.heart2 = sfSprite_create();
	evs.score = 0;
	evs.missed = 0;
	evs.speed = 0;
	evs.baf = 0;
	evs.back_forth = 0;
	evs.mode.width = 1280;
	evs.mode.height = 769;
	evs.mode.bitsPerPixel = 32;
	evs.mode2.width = 552;
	evs.mode2.height = 769;
	evs.mode2.bitsPerPixel = 32;
	return (evs);
}

struct ev init_value(struct ev evs)
{
	sfVector2f pos = { 1125, 675 };

	evs = set_value(evs);
	evs.bg = sfTexture_createFromFile("./assets/bg.png", NULL);
	evs.dk = sfTexture_createFromFile("./assets/ss.png", NULL);
	evs.ch = sfTexture_createFromFile("./assets/ch.png", NULL);
	evs.pause = sfTexture_createFromFile("./assets/pause.png", NULL);
	evs.scor = sfTexture_createFromFile("./assets/score.png", NULL);
	evs.background = sfSprite_create();
	evs.duck = sfSprite_create();
	evs.crosshair = sfSprite_create();
	evs.ps = sfSprite_create();
	evs.sc = sfSprite_create();
	evs.game = sfMusic_createFromFile("./assets/sound/game.wav");
	evs.font = sfFont_createFromFile("./assets/duckhunt.ttf");
	evs.great = sfText_create();
	sfText_setPosition(evs.great, pos);
	sfText_setFont(evs.great, evs.font);
	return (evs);
}

int main(void)
{
	sfRenderWindow *window;
	sfEvent event;
	sfIntRect rect = set_rect(rect);
	sfClock *clock = sfClock_create();
	sfTime time;
	float seconds;
	struct ev evs = init_value(evs);

	if (menu(window, evs) == 1)
		return (EXIT_SUCCESS);
	window = sfRenderWindow_create(evs.mode, "My_Hunter", sfClose, NULL);
	sfRenderWindow_setKeyRepeatEnabled(window, sfFalse);
	set_texture(evs, window, evs.game);
	while (sfRenderWindow_isOpen(window)) {
		evs.mouse_pos = sfMouse_getPositionRenderWindow(window);
		evs.duck_pos = sfSprite_getPosition(evs.duck);
		while (sfRenderWindow_pollEvent(window, &event))
			evs = event_sc(window, &event, evs);
		is_end(evs, window);
		mouse_cursor(evs, window);
		evs.baf = move_sprite(evs.duck, evs.baf, evs.speed);
		time = sfClock_getElapsedTime(clock);
		seconds = time.microseconds / 1000000.0;
		if (seconds > 0.1) {
			evs.back_forth = move_rect(&rect, evs.duck, evs.back_forth);
			sfClock_restart(clock);
		}
		render_window(window, evs);
	}
	destroy(evs, window);
	return (EXIT_SUCCESS);
}
