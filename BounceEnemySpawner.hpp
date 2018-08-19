#ifndef BOUNCE_ENEMY_SPAWNER_HPP
#define BOUNCE_ENEMY_SPAWNER_HPP

#include "EnemySpawner.hpp"

class BounceEnemySpawner : public EnemySpawner{

public:
    BounceEnemySpawner(int rate);
    int update(int);
    
};

#endif