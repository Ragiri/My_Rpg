/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** item
*/

#include "my.h"
#include "struct.h"

item_t *init_item(char *str, char *name, sfVector2f s_pos, sfVector2f t_pos)
{
    item_t *item = malloc(sizeof(item_t));
    static int i = 0;

    item->sprite = sprite_create(str, rect_create(0, 0, 86, 86), s_pos);
    item->name = txt_menu(40, sfWhite, t_pos, name);
    item->rank = i;
    i += 1;
    return (item);
}

void create_item(inventory_t *inv)
{
    inv->print = 3;
    add_element_nrank(inv->item, init_item("ressources/assets/1_kb.png",
    "Kingdom Key", vectorf(430, 10), vectorf(540, 10)), inv->item->nb_element);
    add_element_nrank(inv->item, init_item("ressources/assets/2_kb.png",
    "Oblivion", vectorf(430, 310), vectorf(540, 310)), inv->item->nb_element);
    add_element_nrank(inv->item, init_item("ressources/assets/potion.png",
    "Potion", vectorf(430, 110), vectorf(540, 110)), inv->item->nb_element);
    add_element_nrank(inv->item, init_item("ressources/assets/Ether.png",
    "Ether", vectorf(430, 210), vectorf(540, 210)), inv->item->nb_element);
    add_element_nrank(inv->item, init_item("ressources/assets/3_kb.png",
    "Olympia", vectorf(430, 410), vectorf(540, 410)), inv->item->nb_element);
    add_element_nrank(inv->item, init_item("ressources/assets/4_kb.png",
    "Soul Eater", vectorf(430, 510), vectorf(540, 510)),
    inv->item->nb_element);
}
