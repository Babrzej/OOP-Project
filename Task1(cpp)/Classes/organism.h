#pragma once

class World; 

class Organism {

public:
    typedef struct {
        int x, y;
    } Position;
    Organism(int strength, int initiative);
    ~Organism();
    virtual void action() = 0; 
    virtual void collision() = 0; 
    virtual void draw();
    const Position getPosition();
    void setWorld(World* world);

protected:
    char chr; 
    int strength;
    int initiative;
    Position position, prevPosition;
    World* world = nullptr;
};