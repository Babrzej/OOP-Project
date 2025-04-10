#pragma once

class World; 

class Organism {

public:
    struct Position{
        int x, y;
        Position() : x(0), y(0) {};
        Position(int x, int y) : x(x), y(y) {};
        bool operator==(const Position& other) const {
            return x == other.x && y == other.y;
        }
    };
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