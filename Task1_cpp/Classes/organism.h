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