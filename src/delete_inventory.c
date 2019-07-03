/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** delete inventory
*/

#include "my.h"
#include "struct.h"

void but_del(sfRenderWindow *window, sfText *txt, int *rank, inventory_t *inv)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (inv->item->element != inv->item->first) {
        if (button_is_clicked(txt, mouse, vectorf(150, 60)) == 1) {
            sfText_setColor(txt, (sfColor){255, 0, 0, 255});
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                remove_element_nrank(inv->item,
                ((item_t *)inv->item->element->data)->rank);
                inv->print -= 1;
                *rank -= 1;
            }
        }
    }
}

void display_del(inventory_t *inv, sfRenderWindow *window)
{
    int i = 0;

    inv->item->element = inv->item->first;
    while (i != inv->print) {
        sfRenderWindow_drawSprite(window,
        ((item_t *)inv->item->element->data)->sprite, NULL);
        sfRenderWindow_drawText(window,
        ((item_t *)inv->item->element->data)->name, NULL);
        sfText_setColor(((item_t *)inv->item->element->data)->name,
        (sfColor){255, 255, 255, 255});
        but_del(window, ((item_t *)inv->item->element->data)->name, &i, inv);
        inv->item->element = inv->item->element->next;
        i += 1;
    }
}

void delete_inv(inventory_t *i, game_t *game)
{
    if (game->scene == D_ITEM) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            game->scene = INVENTORY;
        inventory_draw(i, game->window);
        display_del(i, game->window);
        but_inv(i, game);
        but_inv_bis(i, game);
        sfRenderWindow_display(game->window);
        sfRenderWindow_clear(game->window, sfBlack);
    }
}
