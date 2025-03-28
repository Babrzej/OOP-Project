#pragma once

class World; 

class Organism {

protected:
    char chr; 
    int strength;
    int initiative;
    int pX, pY;
    World* world = nullptr;

public:
    Organism(int strength, int initiative, int pX, int pY, World* world);
    ~Organism();
    virtual void action() = 0; 
    virtual void collision() = 0; 
    virtual void draw();
};