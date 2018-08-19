#include "ShootEnemy.hpp"
#include "ShootEnemySpawner.hpp"
#include "EnemySpawner.hpp"
#include "Game.hpp"
#include <stdlib.h>

ShootEnemySpawner::ShootEnemySpawner(int rate) : EnemySpawner(rate){

}

int ShootEnemySpawner::update(int){
    int yPos = rand() % (Game::sY - 2) + 1 ;
    Enemy *e = new ShootEnemy(getX() - getX() % 2, yPos, 3, -1, 0, '3', "Enemy");
    Game::addUnit(e);
    return (1);
}