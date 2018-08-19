#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <ncurses.h>
#include "Unit.hpp"

class Player : public Unit{

private:
    int attackDelay;
    bool respawn;

public:
    Player(int x, int y, int s,char c, std::string t);
    void fire();
    int update(int);
    void colide(std::string type);
};

#endif