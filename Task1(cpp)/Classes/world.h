#pragma once
#include "Organism.h"

class World {
    private:
        Organism *organisms;
    
    public:
        World World::makeTurn();
        World World::drawWorld();
};