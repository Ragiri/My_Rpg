/*
** EPITECH PROJECT, 2019
** init_player
** File description:
** init_player
*/

#include "my.h"
#include "struct.h"

static char **read_file(char *filepath)
{
    struct stat buffer;
    int file_size = 0;
    int fd = open(filepath, O_RDONLY);
    char *str = NULL;
    char **tmp = NULL;

    if (stat(filepath, &buffer) < 0 || fd < 0)
        return (NULL);
    file_size = buffer.st_size;
    str = malloc(sizeof(char) * (file_size + 1));
    if (read(fd, str, file_size) < 0 || file_size == 0)
        return (NULL);
    str[file_size] = '\0';
    if (str[file_size - 1] == '\n')
        str[file_size - 1] = '\0';
    close(fd);
    tmp = parser(str, "\n:");
    if (my_strcmp(tmp[0], "11223311229900123454321") != 0)
        return (NULL);
    return (tmp + 1);
}

stat_t *init_sora(char **file)
{
    stat_t *sora = malloc(sizeof(*sora));

    if (file == NULL)
        return (NULL);
    if (my_strcmp(file[0], "lvl") != 0 || my_strcmp(file[2], "exp")
        || my_strcmp(file[4], "exp_max") != 0 || my_strcmp(file[6], "hp")
        || my_strcmp(file[8], "hp_max") != 0 || my_strcmp(file[10], "mana")
        || my_strcmp(file[12], "mana_max") != 0 || my_strcmp(file[14], "def")
        || my_strcmp(file[16], "atk") != 0)
        return (NULL);
    sora->lvl = my_getnbr(file[1]);
    sora->exp = my_getnbr(file[3]);
    sora->exp_max = my_getnbr(file[5]);
    sora->hp = my_getnbr(file[7]);
    sora->hp_max = my_getnbr(file[9]);
    sora->mana = my_getnbr(file[11]);
    sora->mana_max = my_getnbr(file[13]);
    sora->def = my_getnbr(file[15]);
    sora->atk = my_getnbr(file[17]);
    return (sora);
}

stat_t *init_dingo(char **file)
{
    stat_t *dingo = malloc(sizeof(*dingo));

    if (file == NULL)
        return (NULL);
    if (my_strcmp(file[0], "lvl") != 0 || my_strcmp(file[2], "exp")
        || my_strcmp(file[4], "exp_max") != 0 || my_strcmp(file[6], "hp")
        || my_strcmp(file[8], "hp_max") != 0 || my_strcmp(file[10], "mana")
        || my_strcmp(file[12], "mana_max") != 0 || my_strcmp(file[14], "def")
        || my_strcmp(file[16], "atk") != 0)
        return (NULL);
    dingo->lvl = my_getnbr(file[1]);
    dingo->exp = my_getnbr(file[3]);
    dingo->exp_max = my_getnbr(file[5]);
    dingo->hp = my_getnbr(file[7]);
    dingo->hp_max = my_getnbr(file[8]);
    dingo->mana = my_getnbr(file[11]);
    dingo->mana_max = my_getnbr(file[13]);
    dingo->def = my_getnbr(file[15]);
    dingo->atk = my_getnbr(file[17]);
    return (dingo);
}

stat_t *init_donald(char **file)
{
    stat_t *donald = malloc(sizeof(*donald));

    if (file == NULL)
        return (NULL);
    if (my_strcmp(file[0], "lvl") != 0 || my_strcmp(file[2], "exp")
        || my_strcmp(file[4], "exp_max") != 0 || my_strcmp(file[6], "hp")
        || my_strcmp(file[8], "hp_max") != 0 || my_strcmp(file[10], "mana")
        || my_strcmp(file[12], "mana_max") != 0 || my_strcmp(file[14], "def")
        || my_strcmp(file[16], "atk") != 0)
        return (NULL);
    donald->lvl = my_getnbr(file[1]);
    donald->exp = my_getnbr(file[3]);
    donald->exp_max = my_getnbr(file[5]);
    donald->hp = my_getnbr(file[7]);
    donald->hp_max = my_getnbr(file[9]);
    donald->mana = my_getnbr(file[11]);
    donald->mana_max = my_getnbr(file[13]);
    donald->def = my_getnbr(file[15]);
    donald->atk = my_getnbr(file[17]);
    return (donald);
}

stat_t **init_stat(void)
{
    stat_t **stat = malloc(sizeof(*stat) * (3 + 1));

    stat[3] = NULL;
    stat[0] = init_sora(read_file("./.sora"));
    stat[1] = init_dingo(read_file("./.dingo"));
    stat[2] = init_donald(read_file("./.donald"));
    for (int i = 0; i != 3; i += 1)
        if (stat[i] == NULL)
            return (NULL);
    return (stat);
}
