/*
** EPITECH PROJECT, 2019
** add_remove_element
** File description:
** add and remove element from the list
*/

#include "my.h"

void add_element_nrank(list_t *list, void *data, int rank)
{
    element_t *new = malloc(sizeof(element_t));

    list->element = list->first;
    new->data = data;
    if (rank > list->nb_element + 1)
        return;
    for (int i = 1; i < rank - 1; i += 1)
        list->element = list->element->next;
    if (rank == 0) {
        new->next = list->first;
        list->first = new;
    } else {
        new->next = list->element->next;
        list->element->next = new;
    }
    list->nb_element += 1;
}

void remove_element_nrank(list_t *list, int rank)
{
    element_t *delete;

    if (rank > list->nb_element)
        return;
    list->element = list->first;
    for (int i = 1; i < rank - 1; i += 1)
        list->element = list->element->next;
    if (rank == 0) {
        delete = list->first;
        list->first = list->first->next;
        free(delete);
    } else {
        delete = list->element->next;
        list->element->next = list->element->next->next;
        free(delete);
    }
    list->nb_element -= 1;
}
