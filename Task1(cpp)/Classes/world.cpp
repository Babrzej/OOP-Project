#include "world.h"
#include <iostream>

World::World(std::vector<Organism*> organisms) 
    : organisms(organisms) {
    for(Organism* organism : organisms) {
        organism->setWorld(this);
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
            for (Organism* organism : organisms) {
                Organism::Position pos = organism->getPosition();
                if (pos.x == x && pos.y == y) {
                    organism->draw(); // Draw the organism
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

void World::makeTurn() {
    for(Organism* organism : organisms) {
        organism->action();
    }
}

std::vector<Organism*> World::getOrganisms() {
    return this->organisms;
}