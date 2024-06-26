#ifndef ENUMS_H
#define ENUMS_H
enum GameControls {
    RIGHT = 'd',
    UP = 'w',
    DOWN = 's',
    LEFT = 'a',
    BTN_1 = ' ',
    BTN_2 = 't',
    BTN_3 = 'e',
    BTN_4 = 'r',
    BTN_5 = 'k',
    BTN_6 = ' ',
    NONE = -1,
    ACCELERO = 'q'
};

enum EnemyTypes { // Text value and cost for director
    NORMAL = 150,
};

enum PageNb {
    GAMEPLAY_SCREEN = 1,
    CREDITS_SCREEN = 2,
    TITLE_SCREEN = 3,
    GAMEOVER_SCREEN=4
};
#endif