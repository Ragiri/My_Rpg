/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** inventory
*/

#include "my.h"
#include "struct.h"

inventory_t *init_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    inventory->player = init_ally();
    inventory->rect_sh = malloc(sizeof(sfRectangleShape*) * 4);
    inventory->rect_sh[0] = rectsh_create(sfTransparent, sfWhite,
    rect_create(10, 10, 500, 400), 3);
    inventory->rect_sh[1] = rectsh_create(sfTransparent, sfWhite,
    rect_create(420, 10, 1025, 1490), 3);
    inventory->rect_sh[2] = rectsh_create(sfTransparent, sfWhite,
    rect_create(10, 935, 100, 400), 3);
    inventory->inv = sprite_create("ressources/assets/menu_option_bg.jpg",
    rect_create(0, 0, 1080, 1920), vectorf(0, 0));
    inventory->v_item = txt_menu(60, sfWhite, vectorf(15, 160), "View Item");
    inventory->del = txt_menu(60, sfWhite, vectorf(15, 260), "Delete Item");
    inventory->quit = txt_menu(60, sfWhite, vectorf(50, 945), "Quit");
    inventory->info = txt_menu(60, sfWhite, vectorf(15, 60), "Info");
    inventory->item = init_list();
    create_item(inventory);
    return (inventory);
}

void inventory_setpos(inventory_t *i, sfRenderWindow *window)
{
    sfText_setPosition(i->player[0]->name, vectorf(570, 50));
    sfText_setPosition(i->player[1]->name, vectorf(570, 350));
    sfText_setPosition(i->player[2]->name, vectorf(570, 650));
    sfSprite_setPosition(i->player[0]->art_s, vectorf(450, 50));
    sfSprite_setPosition(i->player[1]->art_s, vectorf(450, 350));
    sfSprite_setPosition(i->player[2]->art_s, vectorf(450, 650));
    sfSprite_setTextureRect(i->player[0]->art_s, rect_create(0, 0, 100, 100));
    sfRenderWindow_drawText(window, i->player[0]->name, NULL);
    sfRenderWindow_drawText(window, i->player[1]->name, NULL);
    sfRenderWindow_drawText(window, i->player[2]->name, NULL);
    sfRenderWindow_drawSprite(window, i->player[0]->art_s, NULL);
    sfRenderWindow_drawSprite(window, i->player[1]->art_s, NULL);
    sfRenderWindow_drawSprite(window, i->player[2]->art_s, NULL);
}

void inventory_draw(inventory_t *i, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, i->inv, NULL);
    sfRenderWindow_drawRectangleShape(window, i->rect_sh[0], NULL);
    sfRenderWindow_drawRectangleShape(window, i->rect_sh[1], NULL);
    sfRenderWindow_drawRectangleShape(window, i->rect_sh[2], NULL);
    sfRenderWindow_drawText(window, i->v_item, NULL);
    sfRenderWindow_drawText(window, i->del, NULL);
    sfRenderWindow_drawText(window, i->quit, NULL);
    sfRenderWindow_drawText(window, i->info, NULL);
    sfText_setColor(i->quit, sfWhite);
    sfText_setColor(i->del, sfWhite);
    sfText_setColor(i->v_item, sfWhite);
    sfText_setColor(i->info, sfWhite);
}

void but_inv(inventory_t *i, game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);

    if (button_is_clicked(i->quit, mouse, vectorf(150, 60)) == 1) {
        sfText_setColor(i->quit, (sfColor){255, 0, 0, 255});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            game->scene = GAME;
    }
    if (button_is_clicked(i->del, mouse, vectorf(370, 60)) == 1) {
        sfText_setColor(i->del, (sfColor){255, 0, 0, 255});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            game->scene = D_ITEM;
    }
}

void inventory_l(game_t *game, inventory_t *inventory)
{
    if (game->scene == INVENTORY) {
        if (sfKeyboard_isKeyPressed(sfKeyReturn))
            game->scene = GAME;
        inventory_draw(inventory, game->window);
        inventory_setpos(inventory, game->window);
        print_stat(inventory->player[0], game->window, 10, -25);
        print_stat(inventory->player[1], game->window, 310, 0);
        print_stat(inventory->player[2], game->window, 610, 25);
        but_inv(inventory, game);
        but_inv_bis(inventory, game);
        sfRenderWindow_display(game->window);
        sfRenderWindow_clear(game->window, sfBlack);
    }
}