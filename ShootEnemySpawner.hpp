#ifndef SHOOT_ENEMY_SPAWNER_HPP
#define SHOOT_ENEMY_SPAWNER_HPP

#include "EnemySpawner.hpp"

class ShootEnemySpawner : public EnemySpawner{

public:
    ShootEnemySpawner(int rate);
    int update(int);
    
};

#endif