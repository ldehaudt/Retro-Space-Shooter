#include "BounceEnemy.hpp"
#include "BounceEnemySpawner.hpp"
#include "EnemySpawner.hpp"
#include "Game.hpp"
#include <stdlib.h>

BounceEnemySpawner::BounceEnemySpawner(int rate) : EnemySpawner(rate){

}

int BounceEnemySpawner::update(int){
    int yPos = rand() % (Game::sY - 2) + 1 ;
    Enemy *e = new BounceEnemy(getX() - getX() % 2, yPos, 3, -1, 1, 'C', "Enemy");
    Game::addUnit(e);
    return (1);
}