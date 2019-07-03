/*
** EPITECH PROJECT, 2018
** my_getnr
** File description:
** Returns a number, sent to the function as a string
*/

int my_getnbr(char const *str)
{
    int nb = 0;
    int nb_of_minus = 0;
    int i = 0;

    for (; str[i] < '0' || str[i] > '9'; i += 1)
        if (str[i] == 45)
            nb_of_minus += 1;
    for (; str[i] >= '0' && str[i] <= '9'; i += 1)
        nb = (nb * 10) + str[i] - 48;
    if (nb_of_minus % 2 != 0)
        nb = nb * -1;
    return (nb);
}
