#include "Unit.hpp"
#include "Game.hpp"
#include <ncurses.h>

Unit::Unit(){

}

Unit::Unit(Unit const &src){
    *this = src;
}

Unit&   Unit::operator=(Unit const &r){
    x = r.getX();
    y = r.getY();
    return *this;
}

int Unit::getX() const{
    return x;
}
    
int Unit::getY() const{
    return y;
}

void Unit::addX(int val){
    x += val;
}

void Unit::addY(int val){
    y += val;
}

void Unit::setX(int val){
    x = val;
}

void Unit::setY(int val){
    y = val;
}

char Unit::getChar() const{
    return c;
}

Unit::~Unit(){

}

Unit::Unit(int xPos, int yPos, int s, char ch, std::string t) : x(xPos), y(yPos), c(ch), speed(s), delay(0), type(t), alive(true){
    color = 1;
    return;
}

int Unit::frame(int key){
    wattron(Game::win, COLOR_PAIR(color));
    if (!alive)
        return (0);
    if (delay == 0)
    {
        delay = speed;
        return (update(key));
    }
    delay--;
    return (1);
}

void Unit::setAlive(bool b){
    alive = b;
}

std::string Unit::getType() const{
    return type;
}

void Unit::moveUp(){
    mvwaddch(Game::win, y, x, ' ');
    if (y > 1){
        y-=1;
    }
}

void Unit::moveDown(){
    mvwaddch(Game::win, y, x, ' ');
    if (y < Game::sY - 4){
        y+=1;
    }
}

void Unit::moveLeft(){
    mvwaddch(Game::win, y, x, ' ');
    if (x > 3){
        x-=2;
    }
}

void Unit::moveRight(){
    mvwaddch(Game::win, y, x, ' ');
    if (x < Game::sX - 6){
        x+=2;
    }
}