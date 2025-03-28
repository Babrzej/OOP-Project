#pragma once

class World; 

class Organism {

public:
    typedef struct {
        int x, y;
    } Position;
    Organism(int strength, int initiative, World* world);
    ~Organism();
    virtual void action() = 0; 
    virtual void collision() = 0; 
    virtual void draw();
    Position getPosition();

protected:
    char chr; 
    int strength;
    int initiative;
    Position position;
    World* world = nullptr;
};