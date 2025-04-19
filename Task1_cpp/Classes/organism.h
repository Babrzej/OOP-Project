#pragma once
#include "position.h"

class World; 
enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    COUNT
};
class Organism {

public:
    Organism(int strength, int initiative);
    ~Organism();
    virtual void action() = 0; 
    virtual void collision(Organism* other) = 0; 
    virtual void draw();
    Position position() const;
    int strength() const;
    void setWorld(World* world);

protected:
    char chr; 
    int _strength;
    int initiative;
    int age;
    Position _position, _prevPosition;
    World* world = nullptr;
};