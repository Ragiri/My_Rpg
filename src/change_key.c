/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** change key
*/

#include "my.h"
#include "struct.h"

keyboard_t *init_key(keyboard_t *key)
{
    key = malloc(sizeof(keyboard_t));
    key->key_up = sfKeyZ;
    key->key_down = sfKeyS;
    key->key_left = sfKeyQ;
    key->key_right = sfKeyD;
    key->inventory = sfKeyI;
    key->interaction = sfKeyE;
    key->up = malloc(sizeof(char) * 2);
    key->down = malloc(sizeof(char) * 2);
    key->left = malloc(sizeof(char) * 2);
    key->right = malloc(sizeof(char) * 2);
    key->inv = malloc(sizeof(char) * 2);
    key->inte = malloc(sizeof(char) * 2);
    key->up[0] = 'Z';
    key->down[0] = 'S';
    key->left[0] = 'Q';
    key->right[0] = 'R';
    key->inv[0] = 'I';
    key->inte[0] = 'E';
    return (key);
}

sfKeyCode change_key(sfKeyCode key_change, char **c)
{
    sfKeyCode key;
    sfTime t = sfMicroseconds(200);

    sfTime_asSeconds(t);
    sfSleep(t);
    if (sfKeyboard_isKeyPressed(key))
        if ((key >= 0 && key <= 35) || (key >= 75 && key <= 84))
            key_change = key;
    if (key_change >= 0 && key_change <= 25)
        *c[0] = key_change + 65;
    if (key_change >= 26 && key_change <= 35)
        *c[0] = key_change + 22;
    if (key_change >= 75 && key_change <= 84)
        *c[0] = key_change - 27;
    return (key_change);
}

void key_option(keyboard_t *key, sfVector2f vect)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (vect.y >= 330 && vect.y <= 370)
            key->key_up = change_key(key->key_up, &key->up);
        if (vect.y >= 390 && vect.y <= 430)
            key->key_down = change_key(key->key_down, &key->down);
        if (vect.y >= 450 && vect.y <= 490)
            key->key_right = change_key(key->key_right, &key->right);
        if (vect.y >= 510 && vect.y <= 560)
            key->key_left = change_key(key->key_left, &key->left);
        if (vect.y >= 580 && vect.y <= 620)
            key->inventory = change_key(key->inventory, &key->inv);
        if (vect.y >= 640 && vect.y <= 680)
            key->interaction = change_key(key->interaction, &key->inte);
    }
}

void key_name_print(sfRenderWindow *window)
{
    sfText *up = txt_menu(50, sfWhite, vectorf(30, 330), "Move Forward");
    sfText *down = txt_menu(50, sfWhite, vectorf(30, 390), "Move Backward");
    sfText *right = txt_menu(50, sfWhite, vectorf(30, 450), "Move Right");
    sfText *left = txt_menu(50, sfWhite, vectorf(30, 510), "Move Left");
    sfText *inventory = txt_menu(50, sfWhite, vectorf(30, 580), "Inventory");
    sfText *inter = txt_menu(50, sfWhite, vectorf(30, 640), "Interactions");

    sfRenderWindow_drawText(window, up, NULL);
    sfRenderWindow_drawText(window, down, NULL);
    sfRenderWindow_drawText(window, right, NULL);
    sfRenderWindow_drawText(window, left, NULL);
    sfRenderWindow_drawText(window, inventory, NULL);
    sfRenderWindow_drawText(window, inter, NULL);
}

void key_print(sfRenderWindow *window, keyboard_t *key)
{
    sfText *key_up = txt_menu(50, sfWhite, vectorf(500, 330), "Z");
    sfText *key_down = txt_menu(50, sfWhite, vectorf(500, 390), "S");
    sfText *key_right = txt_menu(50, sfWhite, vectorf(500, 450), "D");
    sfText *key_left = txt_menu(50, sfWhite, vectorf(500, 510), "Q");
    sfText *inventory = txt_menu(50, sfWhite, vectorf(500, 580), "I");
    sfText *inter = txt_menu(50, sfWhite, vectorf(500, 640), "E");

    sfRenderWindow_drawText(window, key_up, NULL);
    sfRenderWindow_drawText(window, key_down, NULL);
    sfRenderWindow_drawText(window, key_right, NULL);
    sfRenderWindow_drawText(window, key_left, NULL);
    sfRenderWindow_drawText(window, inventory, NULL);
    sfRenderWindow_drawText(window, inter, NULL);
}
