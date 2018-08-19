#ifndef BULLET_HPP
#define BULLET_HPP

#include "Unit.hpp"

class Bullet : public Unit{

private:
    int dX;
    int dY;

public:
    Bullet(int x, int y, int speed, int dx, int dy, char c, std::string t);
    int update(int);
    void colide(std::string type);    

};

#endif