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
    void die();
    bool isDead();
    

    // Getters
    int getStrength() const;
    int getInitiative() const;
    int getAge() const;
    Position getPosition() const;
    Position getPrevPosition() const;

    // Setters
    void setStrength(int strength);
    void setInitiative(int initiative);
    void setAge(int age);
    void setPosition(const Position& position);
    void setPrevPosition(const Position& prevPosition);
    void setWorld(World* world);

protected:
    char chr; 
    int strength;
    int initiative;
    int age;
    bool alive;
    Position position, prevPosition;
    World* world = nullptr;
};