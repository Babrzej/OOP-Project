#include "organism.h"
#include <iostream>

// Default constructor
Organism::Organism(int strength, int initiative) 
    : strength(strength), initiative(initiative), position(position), world(nullptr) {}

// Destructor
Organism::~Organism() {}

void Organism::setWorld(World* world) {
    this->world = world;
}

// Draw method
void Organism::draw() {
    std::cout << chr; // Print the character representation of the organism
}

const Organism::Position Organism::getPosition() {
    return this->position;
}


