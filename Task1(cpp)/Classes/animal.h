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
        Animal(int strength, int initiative, World* world);

        // other methods
        void action() override;
        void collision() override;
};