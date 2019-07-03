/*
** EPITECH PROJECT, 2019
** create_window
** File description:
** create_window
*/

#include "my.h"

sfRenderWindow *create_window(sfVector2f vect, sfBool full)
{
    sfVideoMode video_mode = {vect.x, vect.y, 32};
    char name[] = "My RPG";
    sfRenderWindow *window;

    window = sfRenderWindow_create(video_mode, name,
    full == sfTrue ? sfFullscreen | sfClose : sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_setFramerateLimit(window, 160);
    return (window);
}
