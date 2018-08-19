#include "Bullet.hpp"
#include <ncurses.h>
#include "Game.hpp"

Bullet::Bullet(int x, int y, int s, int dirX, int dirY, char c, std::string t) : Unit(x, y, s, c, t), dX(dirX), dY(dirY) {
    color = 1;
}

int Bullet::update(int){

    mvwaddch(Game::win, getY(), getX(), ' ');
    addX(dX * 2);
    addY(dY);

    if(getX() <= 0 || getX() >= Game::sX - 3 ||
        getY() <= 0 || getY() >= Game::sY - 3)
        return (0);
    return 1;
}

void Bullet::colide(std::string type){
    if (type == "Enemy")
    {
        setAlive(false);
        mvwaddch(Game::win, getY(), getX(), ' ');
    }
}