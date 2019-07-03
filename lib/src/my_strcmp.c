/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** return -1 if str1 < str2, return 0 if str1 = str2, else return 1
*/

#include "my.h"

int my_strlen(char const *str);

int my_strcmp(char *str, char *str2)
{
    int cmp = 0;
    int len_str = my_strlen(str);
    int len_str2 = my_strlen(str2);

    for (int i = 0; str[i] != '\0' && str2[i] != '\0'; i += 1) {
        if (str[i] < str2[i]) {
            cmp = -1;
            break;
        } else if (str[i] > str2[i]) {
            cmp = 1;
            break;
        }
    }
    if (cmp != 0)
        return (cmp);
    if (len_str < len_str2)
        return (-1);
    else if (len_str > len_str2)
        return (1);
    return (0);
}
