#include "Game.hpp"
#include "Unit.hpp"
#include <ncurses.h>

int Game::sX;
int Game::sY;
int Game::lives = 3;
int Game::score;
WINDOW *Game::win;
Unit** Game::units;

void Game::addUnit(Unit *ptr){
    int count;
    for (count = 0; units[count]; count++){
        ;
    }
    Unit** tmp = new Unit*[count + 2];
    tmp[count] = ptr;
    tmp[count + 1] = NULL;
    for (count = 0; units[count]; count++){
        tmp[count] = units[count];
    }
    delete units;
    units = tmp;
}
    
void Game::killUnit(Unit *ptr){
    int count;
    int id = -1;
    wrefresh(win);
    for (count = 0; units[count]; count++){
        if (units[count] == ptr)
            id = count;
    }
     wrefresh(win);
    if (id == -1)
        return;
    Unit** tmp = new Unit*[count];
    tmp[count - 1] = NULL;
    int val = 0;
     wrefresh(win);
    for (count = 0; units[count]; count++){
        if (count == id)
            val--;
        else
            tmp[val] = units[count];
        val++;
    }
     wrefresh(win);
    delete ptr;
    delete units;
    units = tmp;
    wrefresh(win);
}