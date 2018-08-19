#include "Enemy.hpp"
#include "EnemySpawner.hpp"
#include "Game.hpp"
#include <stdlib.h>

EnemySpawner::EnemySpawner(int rate) : Unit(Game::sX - 5, 0, rate, '-', "Spawner"){

}

void EnemySpawner::colide(std::string){

}

int EnemySpawner::update(int){
    int yPos = rand() % (Game::sY - 2) + 1 ;
    Enemy *e = new Enemy(getX() - getX() % 2, yPos, 3, -1, 0, '(', "Enemy");
    Game::addUnit(e);
    return (1);
}