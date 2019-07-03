##
## EPITECH PROJECT, 2019
## lib
## File description:
## makefile
##

SRC		=	src/create_sound.c 	\
			src/color_create.c 	\
			src/create_window.c \
			src/rectsh_create.c \
			src/create_music.c 	\
			src/create_txt.c 	\
			src/create_sprite.c	\
			src/rect_create.c	\
			src/vectorf.c		\
			src/init_game_struct.c	\
			src/init_clock.c	\
			src/parser.c		\
			src/is_char_in_str.c	\
			src/int_to_char.c 	\
			src/my_strcpy.c	\
			src/my_strcmp.c	\
			src/my_strlen.c	\
			src/my_getnbr.c	\
			src/my_strdup.c	\
			src/init_stat.c	\
			src/init_player.c	\
			src/init_ally.c	\

CPPFLAGS	+=	-I./include

OBJ		=	$(SRC:.c=.o)

NAME		=	libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	@cp ../include/*.h ./include
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f *~
	@rm -f *#
	@rm -f vgcore*

re:	fclean clean all

.PHONY:	all re clean fclean
