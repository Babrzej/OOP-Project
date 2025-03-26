#pragma once
#include "World.h"
class Organism {

private:
    int strength;
    int initiative;
    int pX, pY;
    World* world;

public:
    Organism Organism::action();
    Organism Organism::collision();
    Organism Organism::draw();
};