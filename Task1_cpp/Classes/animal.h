#pragma once 
#include "organism.h"
#include "world.h"
#include <cstdlib>



class Animal : public Organism {
    public:
        // constructors
        Animal(int strength, int initiative, int range);

        // other methods
        void action() override;
        void collision(Organism* other) override;
        void moveBack();
    private:
        Direction restriction;
        int range;
};