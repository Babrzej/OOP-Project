#pragma once
#include "Organism.h"

class World {
    private:
        Organism *organisms;
    
    public:
        void makeTurn();
        void drawWorld();
};