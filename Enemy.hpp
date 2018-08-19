#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Unit.hpp"

class Enemy : public Unit{

private:
    int dX;
    int dY;

public:
    Enemy(int x, int y, int speed, int dx, int dy, char c, std::string t);
    virtual void colide(std::string type);
    virtual int update(int);
    int getDX() const;
    int getDY() const;
    void setDX(int);
    void setDY(int);
};

#endif