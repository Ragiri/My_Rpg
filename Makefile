##
## EPITECH PROJECT, 2019
## rpg
## File description:
## makefile
##

SRC		=	src/item.c 				\
			src/delete_inventory.c 		\
			src/inventory_bis.c 			\
			src/inventory.c 			\
			src/change_key.c 			\
			src/main.c 				\
			src/option.c				\
			src/menu.c				\
			src/play.c				\
			src/pause.c				\
			linked_list/list.c			\
			linked_list/add_remove_element.c	\
			titlescreen/titlescreen.c		\
			fight/init_fight.c			\
			fight/init_hud_fight.c			\
			fight/anim_start_fight.c		\
			fight/fight.c				\
			fight/display_fight.c			\
			fight/select_action.c			\
			fight/select_target.c			\
			fight/exec_action.c			\
			fight/init_enemy.c			\
			fight/anim_enemy.c			\
			fight/anim_ally.c			\
			fight/anim_sora.c			\
			fight/attack.c				\
			fight/damage_step.c			\
			fight/ia_control.c			\
			src/movement.c				\
			src/collision.c			\
			src/move_anim.c			\
			src/anim_right.c			\
			src/anim_left.c			\
			src/anim_up.c				\
			src/anim_down.c			\
			src/quest.c				\
			src/move_element.c			\
			src/display_quest.c			\
			src/init_collision.c			\
			src/how_to_play.c			\
			src/create_enemy.c			\
			src/game_over.c			\
			src/man.c				\

OBJ		=	$(SRC:.c=.o)

LIB		=	-L./lib/ -lmy

NAME		=	my_rpg

CPPFLAGS	+=	-I./include

CFLAGS		=	-L./lib -lmy -I./include

CSFMLFLAG	=	-l csfml-system -l csfml-window	\
				-l csfml-graphics -l csfml-audio

all: $(NAME)

$(NAME): $(OBJ)
	@make re -C lib
	@gcc -o $(NAME) $(OBJ) $(CSFMLFLAG) $(CFLAGS)

%.o: %.c
	@gcc -o $@ -c $< -I ./include -L./lib -lmy

clean:
	@rm -f $(OBJ) src/*~ src/*# include/*~ include/*# *~ *#	\
	vgcore.*
	@make -C lib/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C lib/ fclean

re: fclean all
