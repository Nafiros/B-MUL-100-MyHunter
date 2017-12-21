##
## EPITECH PROJECT, 2017
## lib
## File description:
## lib compilation
##

CC	=	gcc

RM	=	rm -f

NAME	=	my_hunter

LIB_SRC_DIR	=	lib/my

LIB_SRC	=	$(LIB_SRC_DIR)/my_printf/my_putstr.c	\
		$(LIB_SRC_DIR)/my_printf/my_put_nbr.c	\
		$(LIB_SRC_DIR)/my_printf/my_putchar.c	\
		$(LIB_SRC_DIR)/my_printf/my_printf.c	\
		$(LIB_SRC_DIR)/my_printf/my_putnbr_base.c	\
		$(LIB_SRC_DIR)/my_printf/my_strlen.c	\
		$(LIB_SRC_DIR)/my_printf/flags1.c	\
		$(LIB_SRC_DIR)/my_printf/flags2.c	\
		$(LIB_SRC_DIR)/my_printf/my_put_ptr.c	\
		$(LIB_SRC_DIR)/my_strcat.c	\
		$(LIB_SRC_DIR)/my_set_nbr.c	\

LIB_OBJ	=	$(LIB_SRC:.c=.o)

SRC	=	src/main.c	\
		src/move.c	\
		src/render.c	\
		src/events.c	\
		src/random.c	\
		src/destroy.c	\
		src/texture.c	\
		src/mouse.c	\
		src/end.c	\
		src/menu.c	\
		src/pause.c	\

CFLAGS	=	-I include

LDFLAGS	=	-L lib -lmy -l c_graph_prog

OBJS	=	$(SRC:.c=.o)

#all:	$(NAME)

$(NAME):	$(LIB_OBJ) $(OBJS)
	ar rc libmy.a $(LIB_OBJ)
	mv libmy.a lib/
	gcc -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(LIB_OBJ)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) lib/libmy.a

re: fclean all

.PHONY: all clean fclean re
