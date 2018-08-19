#include <ncurses.h>
#include "Player.hpp"
#include "Bullet.hpp"
#include "Unit.hpp"
#include "Game.hpp"

Player::Player(int x, int y, int s, char c, std::string t) : Unit(x, y, s, c, t){
    attackDelay = 0;
    color = 2;
    respawn = false;
}

void Player::fire(){
    Bullet *b = new Bullet(getX() + 2, getY(), 5, 2, -1, '/', "Bullet");
    Game::addUnit(b);
    b = new Bullet(getX() + 2, getY(), 5, 2, 1, '\\', "Bullet");
    Game::addUnit(b);
    b = new Bullet(getX() + 2, getY(), 1, 1, 0, '-', "Bullet");
    Game::addUnit(b);
}

int Player::update(int key){
    
    attackDelay--;

    switch (key)
    {
        case KEY_UP:
            Unit::moveUp();
            break;
        case KEY_DOWN:
            Unit::moveDown();
            break;
        case KEY_LEFT:
            Unit::moveLeft();
            break;
        case KEY_RIGHT:
            Unit::moveRight();
            break;
        case ' ':
            if (attackDelay <= 0)
            {
                fire();
                attackDelay = 10;
            }
            break;
        case 'r':
            if (Game::lives > 0 && respawn)
            {
                respawn = false;
                Game::lives--;
                setX(10);
                setY(Game::sY/2);
            }
            break;
        default:
            break;
    }
    return (1);
}

void Player::colide(std::string type){
    if (type == "Enemy" || type == "EBullet")
    {
        setX(-1);
        setY(-1);
        respawn = true;
        mvwaddch(Game::win, getY(), getX(), ' ');
    }
}