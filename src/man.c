/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** man.c
*/

#include "my.h"
#include "struct.h"

static void my_putstr(const char *str)
{
    write(1, str, my_strlen(str));
}

void print_man(void)
{
    my_putstr("\t\t   ////////////////////////////////\n");
    my_putstr("\t\t ///////* Kingdom Hearts *///////\n");
    my_putstr("\t\t////////////////////////////////\n\n");
    my_putstr("\tKingdom Hearts is basicly a series of RPG's video game.\n");
    my_putstr("\tIt's a crossover of various Disney properties based \n");
    my_putstr("\tin a fictional universe. The series centers on the  \n");
    my_putstr("\tmain character, Sora, and his journey and experiences\n");
    my_putstr("\twith various Disney, Square Enix and Pixar characters.\n");
    my_putstr("\tThe heroes of the series clash against the multiple\n");
    my_putstr("\tincarnations of the primary antagonist, Xehanort,\n");
    my_putstr("\tthroughout the series.\n\n");
    my_putstr("\tFor the my_rpg project, we chose to make a game based\n on");
    my_putstr("\tthe theme of kingdom hearts but by implementing our own\n");
    my_putstr("\tgameplay.We hope you will enjoy it and we wish you a good\n");
    my_putstr("\tgame.\n\n\tSincerly,\n\n\tMatthieu VEIGA, Mathis RODRIGUES");
    my_putstr(", Julien MERTIAN DE MULLER et Angelina COLAS\n");
}