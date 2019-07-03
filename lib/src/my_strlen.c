/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** It counts and displays the number of characters in a string
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i += 1);
    return (i);
}
