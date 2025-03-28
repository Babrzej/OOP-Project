#pragma once 
#include "organism.h"

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    COUNT
};

class Animal : public Organism {
    public:
        // constructors
        Animal(int strength, int initiative, int pX, int pY, World* world);

        // other methods
        void action() override;
        void collision() override;
};