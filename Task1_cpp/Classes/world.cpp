#include "world.h"
#include "organism.h" // Include Organism here
#include <iostream>

World::World(std::vector<Organism*> organisms) 
    : organisms(organisms) {
    for(Organism* organism : organisms) {
        organism->setWorld(this);
        organism->setPosition(organism->getRandomValidPosition());
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
    system("cls");
    // Draw the top border
    for (int x = 0; x < width + 2; x++) { // Add 2 for borders
        std::cout << '*';
    }
    std::cout << std::endl;

    // Draw the middle rows
    for (int y = 0; y < height; y++) {
        std::cout << '*'; // Left border
        for (int x = 0; x < width; x++) {
            if (grid[x][y].occupied && !grid[x][y].organism->isDead()) {
                grid[x][y].organism->draw(); // Draw the organism
            } else {
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
    sortOrganisms();
    for(Organism* organism : organisms) {
        organism->action();
        Position pos = organism->getPosition();
        if(grid[pos.x][pos.y].occupied && grid[pos.x][pos.y].organism != organism) {
            Organism* other = grid[organism->getPosition().x][organism->getPosition().y].organism;
            other->collision(organism);
        }
        else {
            this->occupyGrid(organism);
        }
        this->kill();
        
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

void World::sortOrganisms() {
    std::sort(organisms.begin(), organisms.end(), [](Organism* a, Organism* b) {
        // Sort by initiative first (descending)
        if (a->getInitiative() != b->getInitiative()) {
            return a->getInitiative() > b->getInitiative();
        }
        // If initiative is the same, sort by age (descending)
        return a->getAge() > b->getAge();
    });
}

Organism* World::getOrganismAt(Position position) {
    return grid[position.x][position.y].organism;
}

void World::announce() {
    this->announcer.announce();
}
