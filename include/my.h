/*
** EPITECH PROJECT, 2019
** include
** File description:
** my.h
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

#ifndef MY_H_
#define MY_H_

void key_name_print(sfRenderWindow *window);
sfSound *create_sound(char *str, float vol);
sfColor color_create(int r, int g, int b, int a);
sfRenderWindow *create_window(sfVector2f vect, sfBool full);
char *my_itoa(int i);
sfRectangleShape *rectsh_create(sfColor f, sfColor o, sfIntRect r, float i);
sfMusic *music_create(char *str, float vol);
sfText *txt_create(int size, sfColor color, sfVector2f pos, char *n);
sfIntRect rect_create(int top, int left, int height, int width);
sfSprite *sprite_create(char *str, sfIntRect rect, sfVector2f pos);
sfVector2f vectorf(float x, float y);
sfText *txt_menu(int size, sfColor color, sfVector2f pos, char *n);
sfText *txt_pause(int size, sfColor color, sfVector2f pos, char *n);
char **parser(char *str, char *sep);
char *my_strncpy(char *dest, char const *src, int n);
int my_strcmp(char *str, char *str2);
int my_strlen(char const *str);
int my_getnbr(char *str);
char *my_itoa(int nb);
char *my_strdup(char *str);
int is_char_in_str(char c, char *str);
sfRectangleShape *col_c(sfColor f, sfColor o, sfIntRect r, float i);

/* LINKED_LIST */
typedef struct element_s {
    void *data;
    struct element_s *next;
} element_t;

typedef struct list_s {
    int nb_element;
    element_t *element;
    element_t *first;
} list_t;

void free_list(list_t *list);
list_t *init_list(void);
void display_list(list_t *list);
void add_element_nrank(list_t *list, void *data, int rank);
void remove_element_nrank(list_t *list, int rank);

#endif /* !MY_H_ */
