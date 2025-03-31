#include "organism.h"
#include "world.h"
#include <iostream>

// Default constructor
Organism::Organism(int strength, int initiative) 
    : _strength(strength), initiative(initiative), world(nullptr) {}

// Destructor
Organism::~Organism() {}

void Organism::setWorld(World* world) {
    this->world = world;
}

// Draw method
void Organism::draw() {
    std::cout << chr; // Print the character representation of the organism
}

Organism::Position Organism::position() const {
    return this->_position;
}

int Organism::strength() const {
    return this->_strength;
}






