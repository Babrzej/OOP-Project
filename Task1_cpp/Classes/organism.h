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
    virtual ~Organism();
    virtual void action() = 0; 
    virtual void collision(Organism* other) = 0; 
    virtual void draw();
    bool isDead();
    void die();
    Position getRandomValidPosition();
    virtual Position getNewValidPosition();
    

    // Getters
    int getStrength() const;
    int getInitiative() const;
    int getAge() const;
    Position getPosition() const;
    Position getPrevPosition() const;
    int getRange() const;

    // Setters
    void setStrength(int strength);
    void setInitiative(int initiative);
    void setAge(int age);
    void setPosition(const Position& position);
    void setWorld(World* world);
    void setRange(int range);
    void setPrevPosition(const Position& prevPosition);

protected:
    char skin; 
    int strength;
    int initiative;
    int range;
    int age;
    bool alive;
    Position position, prevPosition;
    World* world;
};