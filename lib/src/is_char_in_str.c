/*
** EPITECH PROJECT, 2019
** is_char_in_str
** File description:
** The function returns 1 if char specified is in str, else return 0
*/

#include "my.h"

int is_char_in_str(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1)
        if (str[i] == c)
            return (1);
    return (0);
}
