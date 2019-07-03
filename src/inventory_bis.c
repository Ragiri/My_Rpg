/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** inventory bis
*/

#include "my.h"
#include "struct.h"

void but_inv_bis(inventory_t *i, game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);

    if (button_is_clicked(i->v_item, mouse, vectorf(350, 60)) == 1) {
        sfText_setColor(i->v_item, (sfColor){255, 0, 0, 255});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            game->scene = V_ITEM;
    }
    if (button_is_clicked(i->info, mouse, vectorf(350, 60)) == 1) {
        sfText_setColor(i->info, (sfColor){255, 0, 0, 255});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            game->scene = INVENTORY;
    }
}

void print_stat_bis(player_t *p, sfRenderWindow *window, int ofs)
{
    p->stat->txt[7] = txt_menu(20, sfGreen, vectorf(635, 140 + ofs), "/");
    p->stat->txt[8] = txt_menu(20, sfCyan, vectorf(635, 180 + ofs), "/");
    p->stat->txt[9] = txt_menu(20, sfBlue, vectorf(540, 260 + ofs), "DEF:");
    p->stat->txt[10] = txt_menu(20, sfRed, vectorf(540, 220 + ofs), "ATK:");
    p->stat->txt[11] = txt_menu(20, sfRed, vectorf(600, 220 + ofs),
    my_itoa(p->stat->atk));
    p->stat->txt[12] = txt_menu(20, sfBlue, vectorf(600, 260 + ofs),
    my_itoa(p->stat->def));
    sfRenderWindow_drawText(window, p->stat->txt[6], NULL);
    sfRenderWindow_drawText(window, p->stat->txt[7], NULL);
    sfRenderWindow_drawText(window, p->stat->txt[8], NULL);
    sfRenderWindow_drawText(window, p->stat->txt[9], NULL);
    sfRenderWindow_drawText(window, p->stat->txt[10], NULL);
    sfRenderWindow_drawText(window, p->stat->txt[11], NULL);
    sfRenderWindow_drawText(window, p->stat->txt[12], NULL);
}

void print_stat(player_t *p, sfRenderWindow *window, int ofs, int i)
{
    p->stat->txt = malloc(sizeof(sfText*) * 20);
    p->stat->txt[0] = txt_create(80, sfYellow, vectorf(740 + i, 50 + ofs),
    my_itoa(p->stat->lvl));
    p->stat->txt[1] = txt_menu(20, sfCyan, vectorf(600, 180 + ofs),
    my_itoa(p->stat->mana));
    p->stat->txt[2] = txt_menu(20, sfCyan, vectorf(650, 180 + ofs),
    my_itoa(p->stat->mana_max));
    p->stat->txt[3] = txt_menu(20, sfGreen, vectorf(650, 140 + ofs),
    my_itoa(p->stat->hp_max));
    p->stat->txt[4] = txt_menu(20, sfGreen, vectorf(600, 140 + ofs),
    my_itoa(p->stat->hp));
    p->stat->txt[5] = txt_menu(20, sfGreen, vectorf(540, 140 + ofs), "HP:");
    p->stat->txt[6] = txt_menu(20, sfCyan, vectorf(540, 180 + ofs), "Mana:");
    sfRenderWindow_drawText(window, p->stat->txt[0], NULL);
    sfRenderWindow_drawText(window, p->stat->txt[1], NULL);
    sfRenderWindow_drawText(window, p->stat->txt[2], NULL);
    sfRenderWindow_drawText(window, p->stat->txt[3], NULL);
    sfRenderWindow_drawText(window, p->stat->txt[4], NULL);
    sfRenderWindow_drawText(window, p->stat->txt[5], NULL);
    print_stat_bis(p, window, ofs);
}

void display_inv(inventory_t *inv, sfRenderWindow *window)
{
    int i = 0;

    inv->item->element = inv->item->first;
    while (i != inv->print) {
        sfRenderWindow_drawSprite(window,
        ((item_t *)inv->item->element->data)->sprite, NULL);
        sfRenderWindow_drawText(window,
        ((item_t *)inv->item->element->data)->name, NULL);
        inv->item->element = inv->item->element->next;
        i += 1;
    }
}

void inventory_list(inventory_t *inv, game_t *game)
{

    if (game->scene == V_ITEM) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            game->scene = INVENTORY;
        inventory_draw(inv, game->window);
        display_inv(inv, game->window);
        but_inv(inv, game);
        but_inv_bis(inv, game);
        sfRenderWindow_display(game->window);
        sfRenderWindow_clear(game->window, sfBlack);
    }
}