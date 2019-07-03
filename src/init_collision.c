/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_collision
*/

#include "my.h"
#include "struct.h"

void init_col1(play_t *play, sfColor c)
{
    play->rectsh[0] = col_c(c, c, (sfIntRect){2310, 1638, 642, 170}, 0);
    play->rectsh[1] = col_c(c, c, (sfIntRect){2232, 1812, 1458, 25}, 0);
    play->rectsh[2] = col_c(c, c, (sfIntRect){0, 2046, 2568, 78}, 0);
    play->rectsh[3] = col_c(c, c, (sfIntRect){0, 0, 445, 4320}, 0);
    play->rectsh[4] = col_c(c, c, (sfIntRect){0, 0, 1090, 3140}, 0);
    play->rectsh[5] = col_c(c, c, (sfIntRect){1356, 1812, 385, 426}, 0);
    play->rectsh[6] = col_c(c, c, (sfIntRect){1452, 2256, 132, 180}, 0);
    play->rectsh[7] = col_c(c, c, (sfIntRect){2184, 3243, 165, 505}, 0);
    play->rectsh[8] = col_c(c, c, (sfIntRect){2016, 3475, 554, 182}, 0);
    play->rectsh[9] = col_c(c, c, (sfIntRect){2335, 3438, 59, 183}, 0);
    play->rectsh[10] = col_c(c, c, (sfIntRect){1131, 2531, 113, 400}, 0);
    play->rectsh[11] = col_c(c, c, (sfIntRect){3960, 2244, 342, 840}, 0);
    play->rectsh[12] = col_c(c, c, (sfIntRect){3800, 2502, 180, 240}, 0);
    play->rectsh[13] = col_c(c, c, (sfIntRect){3672, 2598, 78, 174}, 0);
    play->rectsh[14] = col_c(c, c, (sfIntRect){4038, 2766, 60, 1524}, 0);
    play->rectsh[15] = col_c(c, c, (sfIntRect){3942, 2946, 942, 174}, 0);
    play->rectsh[16] = col_c(c, c, (sfIntRect){3420, 3780, 2040, 558}, 0);
    play->rectsh[17] = col_c(c, c, (sfIntRect){2580, 3900, 999, 414}, 0);
    play->rectsh[18] = col_c(c, c, (sfIntRect){1446, 4020, 774, 252}, 0);
}

void init_col2(play_t *play, sfColor c)
{
    play->rectsh[19] = col_c(c, c, (sfIntRect){2262, 4164, 335, 144}, 0);
    play->rectsh[20] = col_c(c, c, (sfIntRect){2556, 928, 562, 470}, 0);
    play->rectsh[21] = col_c(c, c, (sfIntRect){3666, 2886, 55, 50}, 0);
    play->rectsh[22] = col_c(c, c, (sfIntRect){3355, 2960, 70, 84}, 0);
    play->rectsh[23] = col_c(c, c, (sfIntRect){3612, 3234, 138, 84}, 0);
    play->rectsh[24] = col_c(c, c, (sfIntRect){3204, 3420, 138, 84}, 0);
    play->rectsh[25] = col_c(c, c, (sfIntRect){3690, 3552, 138, 84}, 0);
    play->rectsh[26] = col_c(c, c, (sfIntRect){2874, 3408, 138, 84}, 0);
    play->rectsh[27] = col_c(c, c, (sfIntRect){1152, 2682, 192, 350}, 0);
    play->rectsh[28] = col_c(c, c, (sfIntRect){1356, 2850, 60, 182}, 0);
    play->rectsh[29] = col_c(c, c, (sfIntRect){1452, 2814, 138, 80}, 0);
    play->rectsh[30] = col_c(c, c, (sfIntRect){1614, 2724, 150, 175}, 0);
    play->rectsh[31] = col_c(c, c, (sfIntRect){1782, 2808, 48, 60}, 0);
    play->rectsh[32] = col_c(c, c, (sfIntRect){2892, 3162, 260, 25}, 0);
    play->rectsh[33] = col_c(c, c, (sfIntRect){3126, 1278, 150, 78}, 0);
    play->rectsh[34] = col_c(c, c, (sfIntRect){3294, 1236, 276, 162}, 0);
    play->rectsh[35] = col_c(c, c, (sfIntRect){3618, 1062, 414, 210}, 0);
}

void init_col3(play_t *play, sfColor c)
{
    play->rectsh[36] = col_c(c, c, (sfIntRect){3750, 1062, 294, 400}, 0);
    play->rectsh[37] = col_c(c, c, (sfIntRect){3800, 1494, 204, 114}, 0);
    play->rectsh[38] = col_c(c, c, (sfIntRect){3890, 1572, 222, 174}, 0);
    play->rectsh[39] = col_c(c, c, (sfIntRect){3936, 1626, 336, 300}, 0);
    play->rectsh[40] = col_c(c, c, (sfIntRect){3309, 2679, 105, 10}, 0);
    play->rectsh[41] = col_c(c, c, (sfIntRect){3546, 2343, 70, 54}, 0);
    play->rectsh[42] = col_c(c, c, (sfIntRect){2090, 1086, 410, 339}, 0);
    play->rectsh[43] = col_c(c, c, (sfIntRect){1935, 1170, 145, 210}, 0);
    play->rectsh[44] = col_c(c, c, (sfIntRect){1721, 1337, 193, 30}, 0);
    play->rectsh[45] = col_c(c, c, (sfIntRect){1720, 1422, 75, 363}, 0);
    play->rectsh[46] = col_c(c, c, (sfIntRect){464, 3632, 1552, 144}, 0);
    play->rectsh[47] = col_c(c, c, (sfIntRect){888, 3484, 160, 126}, 0);
    play->rectsh[48] = col_c(c, c, (sfIntRect){4324, 2056, 110, 170}, 0);
    play->rectsh[49] = col_c(c, c, (sfIntRect){2340, 3711, 310, 193}, 0);
}

void init_all_col(play_t *play)
{
    sfColor c = sfTransparent;

    init_col1(play, c);
    init_col2(play, c);
    init_col3(play, c);
    move_all_col(-2000, -1400, play->rectsh);
}