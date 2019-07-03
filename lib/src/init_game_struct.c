/*
** EPITECH PROJECT, 2019
** init_game_struct
** File description:
** init_game_struct
*/

#include "my.h"
#include "struct.h"

game_t *init_game_struct(void)
{
    game_t *game = malloc(sizeof(*game));

    game->window = create_window(vectorf(1920, 1080), sfTrue);
    game->fps = init_clock();
    game->music = music_create("ressources/music/Dearly Beloved.ogg", 50.0);
    game->ally = init_ally();
    return (game);
}
