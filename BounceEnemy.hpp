#ifndef BOUNCE_ENEMY_HPP
#define BOUNCE_ENEMY_HPP

#include "Enemy.hpp"
#include <iostream>

class BounceEnemy : public Enemy{

public:
    BounceEnemy(int x, int y, int speed, int dx, int dy, char c, std::string t);
    int update(int);

};

#endif