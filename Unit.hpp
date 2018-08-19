#ifndef UNIT_HPP
#define UNIT_HPP

#include <ncurses.h>
#include <iostream>

class Game;

class Unit{

private:
    int x;
    int y;
    char c;
    int speed;
    int delay;
    std::string type;
    bool alive;
    Unit();

public:
    Unit(Unit const &src);
    Unit&   operator=(Unit const &);
    virtual ~Unit();
    Unit(int x, int y, int speed, char c, std::string t);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int getX() const;
    int getY() const;
    void addX(int);
    void addY(int);
    void setX(int);
    void setY(int);
    std::string getType() const;
    void setAlive(bool);
    char getChar() const;
    int frame(int);
    virtual int update(int) = 0;
    virtual void colide(std::string type) = 0;
    int color;
};

#endif