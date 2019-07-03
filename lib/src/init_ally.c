/*
** EPITECH PROJECT, 2019
** init_ally
** File description:
** init_ally
*/

#include "my.h"
#include "struct.h"

static player_t **init_player_ally(player_t **ally)
{
    sfIntRect r = {0, 0, 40, 44};

    ally[0] = init_player("ressources/assets/sora_fight.png",
    "ressources/assets/sora_art.png", "Sora", r);
    r = (sfIntRect){0, 0, 100, 100};
    ally[1] = init_player("ressources/assets/dingo_sprite.png",
    "ressources/assets/dingo_art.png", "Dingo", r);
    r = (sfIntRect){0, 0, 100, 100};
    ally[2] = init_player("ressources/assets/donald_sprite.png",
    "ressources/assets/donald_art.png", "Donald", r);
    sfSprite_setScale(ally[0]->player_s, vectorf(-3, 3));
    return (ally);
}

player_t **init_ally(void)
{
    player_t **ally = malloc(sizeof(*ally) * (3 + 1));
    stat_t **stat = init_stat();

    if (stat == NULL)
        return (NULL);
    ally[3] = NULL;
    ally = init_player_ally(ally);
    for (int i = 0; i != 3; i += 1)
        ally[i]->stat = stat[i];
    for (int i = 0; i != 3; i += 1) {
        sfSprite_setPosition(ally[i]->player_s,
        vectorf(400 + 30 * i, 300 + 200 * i));
    }
    return (ally);
}
