#pragma once 
#include "organism.h"
#include "world.h"
#include <cstdlib>

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
        Animal(int strength, int initiative);

        // other methods
        void action() override;
        void collision(Organism* other) override;
        void moveBack();
    private:
        Direction restriction;
};