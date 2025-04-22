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

int World::getHeight() const {
    return this->height;
}

int World::getWidth() const {
    return this->width;
}
void World::drawWorld() {
    //system("cls");
    // Draw the top border
    for (int x = 0; x < width + 2; x++) { // Add 2 for borders
        std::cout << '*';
    }
    std::cout << std::endl;

    // Draw the middle rows
    for (int y = 0; y < height; y++) {
        std::cout << '*'; // Left border
        for (int x = 0; x < width; x++) {
            bool organismFound = false;
            for (Organism* organism : organisms) {
                Position pos = organism->getPosition(); // Use getter
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
    for (int x = 0; x < width + 2; x++) { // Add 2 for borders
        std::cout << '*';
    }
    std::cout << std::endl;
}

void World::makeTurn() {
    for(Organism* organism : organisms) {
        organism->action();
        if(this->grid[organism->getPosition().x][organism->getPosition().y].occupied == true) {
            organism->collision(this->grid[organism->getPosition().x][organism->getPosition().y].organism);
        }
        else this->occupyGrid(organism);
    }
}

std::vector<Organism*> World::getOrganisms() {
    return this->organisms;
}

void World::kill() {
    // Remove the organism from the vector
    for (auto it = organisms.begin(); it != organisms.end(); ++it) {
        if ((*it)->isDead()) {
            organisms.erase(it);
            delete (*it);
            break;
        }
    }
}

void World::freeGrid(Organism* organism) {
    Position pos = organism->getPosition();
    grid[pos.x][pos.y].organism = nullptr;
    grid[pos.x][pos.y].occupied = false;
}

void World::occupyGrid(Organism* organism) {
    Position pos = organism->getPosition();
    grid[pos.x][pos.y].organism = organism;
    grid[pos.x][pos.y].occupied = true;
}

bool World::isGridOccupied(Position pos) {
    if(grid[pos.x][pos.y].occupied) return true;
    return false;
}