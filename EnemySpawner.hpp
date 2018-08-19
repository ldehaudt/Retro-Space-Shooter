#ifndef ENEMY_SPAWNER_HPP
#define ENEMY_SPAWNER_HPP

class EnemySpawner : public Unit{

public:
    EnemySpawner(int rate);
    int update(int);
    void colide(std::string type);
    
};

#endif