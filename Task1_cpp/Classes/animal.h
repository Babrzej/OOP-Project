#pragma once 
#include "organism.h"
#include "world.h"
#include <cstdlib>



class Animal : public Organism {
    public:
        // constructors
        Animal(int strength, int initiative, int range, char skin);

        // other methods
        void action() override;
        void collision(Organism* other) override;
        virtual Position getNewValidPosition();
        void move();
        void moveBack();


    protected:
        Direction restriction;
        int range;
};