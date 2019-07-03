/*
** EPITECH PROJECT, 2019
** parser
** File description:
** Parse an array in function of separator given in argument
*/

#include "my.h"

static int count_lines(char *str, char *separator)
{
    int nb_lines = 0;

    for (int i = 0; str[i] != '\0'; i += 1)
        if (is_char_in_str(str[i], separator) == 1)
            nb_lines += 1;
    return (nb_lines + 1);
}

int count_len(char *str, char *sep)
{
    int len = 0;

    for (; str[len] != '\0' && is_char_in_str(str[len], sep) == 0; len += 1);
    return (len);
}

char **parser(char *str, char *sep)
{
    int nb_lines;
    int len = 0;
    char **tab = NULL;

    if (sep == NULL)
        return (NULL);
    nb_lines = count_lines(str, sep);
    tab = malloc(sizeof(char *) * (nb_lines + 1));
    tab[nb_lines] = NULL;
    for (int i = 0; str[0] != '\0'; i += 1) {
        len = count_len(str, sep);
        tab[i] = malloc(sizeof(char) * (len + 1));
        tab[i] = my_strncpy(tab[i], str, len);
        str += len;
        if (is_char_in_str(str[0], sep) == 1)
            str += 1;
    }
    return (tab);
}
