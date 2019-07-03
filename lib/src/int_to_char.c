/*
** EPITECH PROJECT, 2019
** lib
** File description:
** itoa
*/

#include "my.h"
#include "struct.h"

char *my_itoa(int nb)
{
    char *str = malloc(sizeof(char) * 500);
    int a = 1;
    int n = 1;
    int i = 0;
    int c = 0;

    for (int i = nb; i >= 10; i /= 10) {
        a *= 10;
        n++;
    }
    if (nb >= 0) {
        for (; n > 0; n--) {
            c = ((nb / a) % 10) + 48;
            a /= 10;
            str[i] = c;
            i++;
        }
    }
    str[i] = '\0';
    return (str);
}