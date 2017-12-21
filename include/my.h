/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** header
*/

#ifndef MY_HUNTER_H
#define MY_HUNTER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#define EXIT_ERROR 84
#define EXIT_SUCCESS 0

#define BLUE    "\x1b[94;1m"
#define GREEN   "\x1b[32m"
#define NORMAL   "\x1b[0m"

struct ev {
	int score;
	int missed;
	float speed;
	sfVector2i mouse_pos;
	sfVector2f duck_pos;
	sfTexture *bg;
	sfTexture *dk;
	sfTexture *ch;
	sfSprite *background;
	sfSprite *duck;
	sfSprite *crosshair;
	int baf;
	int back_forth;
	sfVideoMode mode;
	sfVideoMode mode2;
	sfTexture *menu;
	sfTexture *play;
	sfTexture *play_h;
	sfTexture *quit;
	sfTexture *quit_h;
	sfTexture *credit;
	sfTexture *credit_h;
	sfSprite *m;
	sfSprite *play_button;
	sfSprite *quit_button;
	sfSprite *credit_button;
	sfMusic *game;
	sfTexture *pause;
	sfSprite *ps;
	sfTexture *scor;
	sfSprite *sc;
	sfFont *font;
	sfText *great;
	sfTexture *hrt;
	sfSprite *heart1;
	sfSprite *heart2;
	sfTexture *credit_m;
	sfSprite *credit_menu;
};

void my_putchar(char);
int my_printf(char const *, ...);
void my_putstr(char *);
char *my_strcat(char *, char const *);
int my_strlen(char *);
char *my_set_nbr(int);

void f_c(va_list);
void f_d(va_list);
void f_s(va_list);
void f_o(va_list);
void f_x(va_list);
void f_xu(va_list);
void f_b(va_list);
void f_pe(va_list);
void f_p(va_list);
void f_u(va_list);

int move_rect(sfIntRect *, sfSprite *, int);
int move_sprite(sfSprite *, int, float);
void render_window(sfRenderWindow *, struct ev);
sfIntRect set_rect(sfIntRect);
void destroy(struct ev, sfRenderWindow *);
void set_texture(struct ev, sfRenderWindow *, sfMusic *);
void mouse_cursor(struct ev, sfRenderWindow *);
int rand_nbr(int, int);
struct ev event_sc(sfRenderWindow *, sfEvent *, struct ev);
int event2(sfRenderWindow *, sfEvent *, struct ev);
int is_end(struct ev, sfRenderWindow *);
void hover(sfRenderWindow *, struct ev);
int menu(sfRenderWindow *, struct ev);
void is_pause(struct ev, sfRenderWindow *, sfEvent *);
int my_pause(sfEvent *, sfRenderWindow *, struct ev);

#endif
