/*
** EPITECH PROJECT, 2019
** list
** File description:
** manage list
*/

#include "my.h"

list_t *init_list(void)
{
    list_t *list = malloc(sizeof(list_t));

    list->first = NULL;
    list->element = NULL;
    list->nb_element = 0;
    return (list);
}

void free_list(list_t *list)
{
    element_t *delete;

    if (list == NULL)
        return;
    while (list->first != NULL) {
        delete = list->first;
        list->first = list->first->next;
        free(delete);
    }
    free(list);
}

void display_list(list_t *list)
{
    list->element = list->first;

    while (list->element != NULL) {
        list->element = list->element->next;
    }
}

element_t *move_to_nrank(list_t *list, int nrank)
{
    element_t *move = list->first;

    if (nrank > list->nb_element)
        return (NULL);
    for (int i = 1; i < nrank; i += 1)
        move = move->next;
    return (move);
}
