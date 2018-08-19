#ifndef Shoot_ENEMY_HPP
#define Shoot_ENEMY_HPP

#include "Enemy.hpp"
#include <iostream>

class ShootEnemy : public Enemy{

private:
    int attackDelay; 

public:
    ShootEnemy(int x, int y, int speed, int dx, int dy, char c, std::string t);
    int update(int);
    void fire();
};

#endif