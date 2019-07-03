/*
** EPITECH PROJECT, 2019
** struct
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "my.h"

enum scene_e {
    TITLESCREEN,
    MENU,
    GAME,
    PAUSE,
    ANIM_FIGHT,
    FIGHT,
    INVENTORY,
    EXIT,
    V_ITEM,
    D_ITEM,
    OPTION,
    NILL,
    HOW_TO_PLAY,
    GAME_OVER,
};

enum action_e {
    ATTACK,
    SPELL,
    OBJECT,
    RUN
};

enum player_e {
    SORA,
    DINGO,
    DONALD,
    ENEMY_1,
    ENEMY_2,
    ENEMY_3
};

enum status_e {
    MOVE,
    HIT,
    ATTACKING,
    DEAD,
    ESCAPE
};

enum attack_step_e {
    SELECTION,
    ANIMATION,
    DAMAGE
};

enum fight_e {
    SELECT,
    DO_ACTION,
    NEXT_TURN,
    VICTORY,
    DEFEAT
};

enum quest_e {
    START,
    F_QUEST,
};

typedef struct lose_s{
    sfSprite *spr;
    sfText *restart;
    sfText *menu;
    sfText *quit;
}lose_t;

typedef struct htp_s{
    sfText *txt;
    sfSprite *spr;
}htp_t;

typedef struct pause_s{
    sfText *txt;
    sfSprite *spr;
}pause_t;

typedef struct menu_s{
    sfSprite **bg;
    sfText *start;
    sfText *options;
    sfText *quit;
    sfText *htp;
}menu_t;

typedef struct clocks_s{
    sfClock *clock;
    sfTime time;
    float seconds;
}clocks_t;

typedef struct titlescreen_s {
    sfSprite *bg;
    sfSprite *title;
    sfSprite *white;
    sfText *text;
} titlescreen_t;

typedef struct stat_s{
    int lvl;
    int exp;
    int exp_max;
    int hp;
    int hp_max;
    int mana;
    int mana_max;
    int def;
    int atk;
    sfText **txt;
}stat_t;

typedef struct player_s{
    sfSprite *player_s;
    sfSprite *art_s;
    sfIntRect rect;
    stat_t *stat;
    sfText *name;
    char *str_name;
}player_t;

typedef struct fight_hud_s {
    sfSprite **hp_ally;
    sfSprite **mana;
    sfSprite **face;
    sfText **comm_name;
    sfSprite *command;
    sfSprite *select;
} fight_hud_t;

typedef struct fight_s {
    sfMusic *music;
    sfSprite *bg;
    sfSprite *crown;
    sfSprite *black;
    sfSprite *arrow_1;
    sfSprite *arrow_2;
    fight_hud_t *hud;
    player_t **enemy;
    player_t *target_p;
    enum player_e target_player;
    player_t *actual_p;
    enum player_e actual_player;
    enum action_e action;
    enum fight_e step;
    enum attack_step_e a_step;
} fight_t;

typedef struct keyboard_s{
    sfKeyCode key_up;
    sfKeyCode key_down;
    sfKeyCode key_left;
    sfKeyCode key_right;
    sfKeyCode interaction;
    sfKeyCode inventory;
    char *up;
    char *down;
    char *left;
    char *right;
    char *inv;
    char *inte;
}keyboard_t;

typedef struct inventory_s{
    player_t **player;
    sfRectangleShape **rect_sh;
    sfSprite *inv;
    list_t *item;
    int print;
    sfText *quit;
    sfText *info;
    sfText *v_item;
    sfText *del;
}inventory_t;

typedef struct item_s{
    sfSprite *sprite;
    sfText *name;
    int rank;
}item_t;

typedef struct game_s{
    sfRenderWindow *window;
    clocks_t fps;
    sfEvent event;
    sfMusic *music;
    enum scene_e scene;
    player_t **ally;
}game_t;

typedef struct option_s{
    sfSprite *s;
    sfSound *sound;
}option_t;

typedef struct play_s{
    sfSprite **spr;
    sfSprite **enemy;
    sfIntRect rect;
    sfRectangleShape **rectsh;
    sfText *txt;
    enum quest_e quest;
    sfMusic *music_g;
}play_t;

inventory_t *init_inventory(void);
option_t *init_opt(void);
void key_print(sfRenderWindow *window, keyboard_t *key);
void key_option(keyboard_t *key, sfVector2f vect);
void option_menu(game_t *game, option_t *opt, sfMusic *music,
keyboard_t *key);
player_t *init_player(char *str_p, char *str_a, char *name, sfIntRect r);
int titlescreen(game_t *game, titlescreen_t *title);
int menu_l(game_t *game, keyboard_t *key, menu_t *menu);
void manage_fight_begin(game_t *game, char **enemy, char *bg);
fight_t *start_fight(game_t *game, fight_t *fight);
fight_t *free_fight(fight_t *fight);
int play_l(game_t *game, play_t *play);
int pause_l(game_t *game, play_t *play);
void print_game(sfRenderWindow *window, play_t *play);
void but_inv_bis(inventory_t *i, game_t *game);
void print_stat(player_t *p, sfRenderWindow *window, int ofs, int i);
void inventory_l(game_t *game, inventory_t *inventory);
void create_item(inventory_t *inv);
void but_inv(inventory_t *i, game_t *game);
void delete_inv(inventory_t *i, game_t *game);
void inventory_draw(inventory_t *i, sfRenderWindow *window);
void inventory_list(inventory_t *inv, game_t *game);
void display_inv(inventory_t *inv, sfRenderWindow *window);
void movement(sfRectangleShape **rect, sfSprite **spr, sfSprite **e);
int check_collision(sfSprite *spr, sfRectangleShape **rectsh);
int button_is_clicked(sfText *text, sfVector2i mouse, sfVector2f size);
sfIntRect animation(sfIntRect rect, sfSprite *spr);
sfIntRect rect_transform(sfIntRect rect, int left, int width);
sfIntRect right_anim_r(sfIntRect rect, sfSprite *spr);
sfIntRect right_anim_l(sfIntRect rect, sfSprite *spr);
sfIntRect right_anim_u(sfIntRect rect, sfSprite *spr);
sfIntRect right_anim_d(sfIntRect rect, sfSprite *spr);
int quest_collision(sfSprite **spr);
int trigger_quest(play_t *play, sfRenderWindow *window);
void manage_quest(play_t *play, sfRenderWindow *window);
fight_t *manage_fight(fight_t *fight, game_t *game);
void display_fight(fight_t *fight, sfRenderWindow *window, player_t **ally);
fight_t *select_action(fight_t *fight);
player_t *select_target(player_t **ally, player_t **enemy, fight_t *fight);
void move_element_spr(sfVector2f move, sfSprite **spr);
void move_rect_sh(sfVector2f move, sfRectangleShape **rect);
fight_t *exec_action(fight_t **fight, game_t **game);
player_t **anim_enemy(player_t **enemy, enum status_e status);
player_t **anim_ally(player_t **ally, enum status_e status);
void anim_sora(player_t *sora, enum status_e status);
void anim_sora_move(player_t *sora, enum status_e status, sfIntRect rect);
void anim_groboulet(player_t *sora, enum status_e status, sfIntRect rect);
void anim_soldier(player_t *sora, enum status_e status, sfIntRect rect);
void move_all_col(int x, int y, sfRectangleShape **rect);
void display_quest(play_t *play, sfRenderWindow *window);
int anim_htp(menu_t *menu, game_t *game);
fight_t *manage_attack(fight_t **fight, game_t **game);
fight_t *damage_step(fight_t *fight, game_t *game);
void htp_loop(game_t *game);
play_t *create_enemy(play_t *play);
void move_enemy(sfVector2f move, sfSprite **spr);
void move_all_obj(sfVector2f move, sfSprite **spr, sfSprite **e,
sfRectangleShape **rect);
fight_t *selection(fight_t *fight, game_t *game);
fight_t *manage_selection(fight_t **fight, game_t **game);
int check_enemy(sfSprite **spr, sfSprite **enemy);
void game_over_l(game_t *game, play_t *play);

/* INIT */
void init_all_col(play_t *play);
player_t **init_enemy(char **enemy_str);
player_t **init_ally(void);
stat_t **init_stat(void);
fight_t *init_hud_fight(fight_t *fight);
static char **read_file(char *filepath);
stat_t *init_dingo(char **file);
stat_t *init_sora(char **file);
stat_t *init_donald(char **file);
clocks_t init_clock(void);
game_t *init_game_struct(void);
keyboard_t *init_key(keyboard_t *key);
menu_t *init_menu(void);
titlescreen_t *init_titlescreen(void);
play_t *init_play(void);
pause_t *init_pause(void);
clocks_t *init_clock_p(void);
void print_man(void);

#endif /* !STRUCT_H_ */
