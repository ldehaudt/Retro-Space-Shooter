#include "ShootEnemy.hpp"
#include "Game.hpp"
#include "Bullet.hpp"

ShootEnemy::ShootEnemy(int x, int y, int s, int dirX, int dirY, char c, std::string t) : Enemy(x, y, s, dirX, dirY, c, t){
    attackDelay = rand() % 5 + 9;
    color = 6;
}

void ShootEnemy::fire(){
    Bullet *b = new Bullet(getX() - 2, getY(), 5, -3, -1, 'o', "EBullet");
    Game::addUnit(b);
    b = new Bullet(getX() - 2, getY(), 5, -3, 1, 'o', "EBullet");
    Game::addUnit(b);
}

int ShootEnemy::update(int){
    mvwaddch(Game::win, getY(), getX(), ' ');
    addX(getDX() * 2);
    addY(getDY());
    attackDelay--;
    if (attackDelay == 0){
        fire();
        attackDelay = rand() % 5 + 26;
    }
    if(getX() <= 0 || getX() >= Game::sX - 3 ||
        getY() <= 0 || getY() >= Game::sY - 3)
        return (0);
    return (1);
}