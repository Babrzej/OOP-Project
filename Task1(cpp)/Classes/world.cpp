#include "world.h"
#include <iostream>

World::World(std::vector<Organism*> organisms) 
    : organisms(organisms) {
    for(int i = 0; i < organisms.size(); i++) {
        organisms[i]->setWorld(this);
    }
}

void World::drawWorld() {
    // Draw the top border
    for (int x = 0; x < width; x++) {
        std::cout << '*';
    }
    std::cout << std::endl;

    // Draw the middle rows
    for (int y = 1; y < height - 1; y++) {
        std::cout << '*'; // Left border
        for (int x = 1; x < width - 1; x++) {
            bool organismFound = false;
            for (int k = 0; k < organisms.size(); k++) {
                Organism::Position pos = organisms[k]->getPosition();
                if (pos.x == x && pos.y == y) {
                    organisms[k]->draw(); // Draw the organism
                    organismFound = true;
                    break;
                }
            }
            if (!organismFound) {
                std::cout << ' '; // Empty space
            }
        }
        std::cout << '*'; // Right border
        std::cout << std::endl;
    }

    // Draw the bottom border
    for (int x = 0; x < width; x++) {
        std::cout << '*';
    }
    std::cout << std::endl;
}