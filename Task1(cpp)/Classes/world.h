#pragma once
#include "Organism.h"
#include <vector>
class World {
private:
    std::vector<Organism*> organisms;
    int width = 10, height = 10;
    
public:
    World(std::vector<Organism*> organisms);
    void makeTurn();
    void drawWorld();
};