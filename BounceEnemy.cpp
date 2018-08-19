#include "BounceEnemy.hpp"
#include "Game.hpp"

BounceEnemy::BounceEnemy(int x, int y, int s, int dirX, int dirY, char c, std::string t) : Enemy(x, y, s, dirX, dirY, c, t){

}

int BounceEnemy::update(int){
    mvwaddch(Game::win, getY(), getX(), ' ');
    addX(getDX() * 2);
    addY(getDY());
    if (getY() == 1 || getY() == Game::sY - 4)
        setDY(-getDY());
    if(getX() <= 0 || getX() >= Game::sX - 3 ||
        getY() <= 0 || getY() >= Game::sY - 3)
        return (0);
    return (1);
}