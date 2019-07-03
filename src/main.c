/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** main
*/

#include "my.h"
#include "struct.h"

int game_loo(game_t *game, play_t *play, inventory_t *inv, titlescreen_t *titl)
{
    manage_fight_begin(game,
    (char *[]){"soldier", "groboulet", "soldier", NULL},
    "ressources/assets/inventory_bg.jpg");
    titlescreen(game, titl);
    htp_loop(game);
    play_l(game, play);
    pause_l(game, play);
    inventory_l(game, inv);
    inventory_list(inv, game);
    delete_inv(inv, game);
    game_over_l(game, play);
}

int error_manage(game_t *game, play_t *play)
{
    srand(time(NULL));
    game->scene = TITLESCREEN;
    play->quest = START;
    if (game->ally == NULL) {
        sfMusic_destroy(game->music);
        return (84);
    }
    return (0);
}

int game_loop(keyboard_t *key)
{
    game_t *game = init_game_struct();
    menu_t *menu = init_menu();
    titlescreen_t *title = init_titlescreen();
    play_t *play = init_play();
    inventory_t *inventory = init_inventory();
    option_t *opt = init_opt();

    if (error_manage(game, play) == 84) return (84);
    while (1) {
        game->fps.time = sfClock_getElapsedTime(game->fps.clock);
        if (game->fps.time.microseconds / 1000000.0 < 0.0166)
            continue;
        if (game->scene == EXIT) break;
        game_loo(game, play, inventory, title);
        menu_l(game, key, menu);
        option_menu(game, opt, game->music, key);
        sfClock_restart(game->fps.clock);
    }
    sfRenderWindow_destroy(game->window);
    sfMusic_destroy(game->music);
}

int main(int argc, char **argv, char **env)
{
    keyboard_t *key = NULL;

    if (!env[0])
        return (84);
    if (argc == 2)
        if (my_strcmp(argv[1], "-h") == 0) {
            print_man();
            return (0);
        }
    key = init_key(key);
    game_loop(key);
    return (0);
}
