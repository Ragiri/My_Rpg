/*
** EPITECH PROJECT, 2019
** init_enemy
** File description:
** init_enemy
*/

#include "my.h"
#include "struct.h"

player_t *init_groboulet(int i)
{
    stat_t *stat = malloc(sizeof(*stat));
    player_t *groboulet = init_player("ressources/assets/enemy1.png",
    "ressources/assets/art1.jpg", "groboulet", (sfIntRect){0, 0, 90, 80});

    sfSprite_setTextureRect(groboulet->art_s, (sfIntRect){0, 0, 26, 28});
    sfSprite_setPosition(groboulet->player_s,
    vectorf(1700 - 30 * i, 200 + 200 * i));
    sfSprite_setScale(groboulet->player_s, vectorf(-3, 3));
    stat->hp = 40;
    stat->hp_max = 40;
    stat->def = 15;
    stat->atk = 10;
    groboulet->stat = stat;
    return (groboulet);
}

player_t *init_soldier(int i)
{
    stat_t *stat = malloc(sizeof(*stat));
    player_t *soldier = init_player("ressources/assets/enemy2.png",
    "ressources/assets/art2.png", "soldier", (sfIntRect){0, 0, 45, 60});

    sfSprite_setTextureRect(soldier->art_s, (sfIntRect){0, 0, 26, 28});
    sfSprite_setPosition(soldier->player_s,
    vectorf(1500 - 30 * i, 200 + 200 * i));
    sfSprite_setScale(soldier->player_s, vectorf(3, 3));
    stat->hp = 20;
    stat->hp_max = 20;
    stat->def = 10;
    stat->atk = 15;
    soldier->stat = stat;
    return (soldier);
}

player_t **init_enemy(char **enemy_str)
{
    player_t **enemy = NULL;
    int len = 0;

    for (len = 0; enemy_str[len] != NULL; len += 1);
    enemy = malloc(sizeof(*enemy) * (len + 1));
    enemy[len] = NULL;
    for (int i = 0; enemy_str[i] != NULL; i += 1) {
        if (my_strcmp(enemy_str[i], "groboulet") == 0)
            enemy[i] = init_groboulet(i);
        if (my_strcmp(enemy_str[i], "soldier") == 0)
            enemy[i] = init_soldier(i);
    }
    return (enemy);
}
