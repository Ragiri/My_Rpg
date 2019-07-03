/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** duplicate a string
*/

#include "my.h"

char *my_strdup(char *str)
{
    char *new = NULL;
    int len = 0;

    if (str == NULL)
        return (NULL);
    for (; str[len] != '\0'; len += 1);
    new = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i += 1)
        new[i] = str[i];
    new[len] = '\0';
    return (new);
}
