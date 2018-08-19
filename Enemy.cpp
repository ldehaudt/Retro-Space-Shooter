#include "Enemy.hpp"
#include "Game.hpp"

Enemy::Enemy(int x, int y, int s, int dirX, int dirY, char c, std::string t) : Unit(x, y, s, c, t), dX(dirX), dY(dirY) {
    color = 4;
}

int Enemy::update(int){
    mvwaddch(Game::win, getY(), getX(), ' ');
    addX(dX * 2);
    addY(dY);

    if(getX() <= 0 || getX() >= Game::sX - 3 ||
        getY() <= 0 || getY() >= Game::sY - 3)
        return (0);
    return (1);
}

void Enemy::colide(std::string type){
    if (type == "Bullet")
    {
        setAlive(false);
        mvwaddch(Game::win, getY(), getX(), ' ');
        Game::score += 100;
    }
}

int Enemy::getDX() const{
    return dX;
}

int Enemy::getDY() const{
    return dY;
}

void Enemy::setDX(int i){
    dX = i;
}

void Enemy::setDY(int i){
    dY = i;
}