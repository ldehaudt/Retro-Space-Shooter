#ifndef GAME_HPP
#define GAME_HPP

#include <ncurses.h>

class Unit;

class Game{
public:
    static int sX;
    static int sY;
    static int score;
    static int lives;
    static WINDOW *win;
    static Unit** units;

    static void addUnit(Unit *ptr);
    static void killUnit(Unit *ptr);
};

#endif