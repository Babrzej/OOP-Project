#include "world.h"
#include "organism.h" // Include Organism here
#include <iostream>

World::World(std::vector<Organism*> organisms) 
    : organisms(organisms) {
    for(Organism* organism : organisms) {
        organism->setWorld(this);
        this->occupyGrid(organism);
    }
}

int World::height() const {
    return this->_height;
}

int World::width() const {
    return this->_width;
}
void World::drawWorld() {
    //system("cls");
    // Draw the top border
    for (int x = 0; x < _width + 2; x++) { // Add 2 for borders
        std::cout << '*';
    }
    std::cout << std::endl;

    // Draw the middle rows
    for (int y = 0; y < _height; y++) {
        std::cout << '*'; // Left border
        for (int x = 0; x < _width; x++) {
            bool organismFound = false;
            for (Organism* organism : organisms) {
                Organism::Position pos = organism->position(); // Use getter
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
    for (int x = 0; x < _width + 2; x++) { // Add 2 for borders
        std::cout << '*';
    }
    std::cout << std::endl;
}

void World::makeTurn() {
    for(Organism* organism : organisms) {
        organism->action();
        if(this->grid[organism->position().x][organism->position().y].occupied == true) {
            organism->collision(this->grid[organism->position().x][organism->position().y].organism);
        }
        else this->occupyGrid(organism);
    }
}

std::vector<Organism*> World::getOrganisms() {
    return this->organisms;
}

void World::kill(Organism* organism) {
    // Remove the organism from the vector
    for (auto it = organisms.begin(); it != organisms.end(); ++it) {
        if (*it == organism) {
            organisms.erase(it);
            break;
        }
    }

    // Delete the organism to free memory
    delete organism;
}

void World::freeGrid(Organism* organism) {
    Organism::Position pos = organism->position();
    grid[pos.x][pos.y].organism = nullptr;
    grid[pos.x][pos.y].occupied = false;
}

void World::occupyGrid(Organism* organism) {
    Organism::Position pos = organism->position();
    grid[pos.x][pos.y].organism = organism;
    grid[pos.x][pos.y].occupied = true;
}