#include "organism.h"
#include <iostream>

// Default constructor
Organism::Organism(int strength, int initiative, World* world) 
    : strength(strength), initiative(initiative), position(position), world(nullptr) {}

// Destructor
Organism::~Organism() {}

// Draw method
void Organism::draw() {
    std::cout << chr; // Print the character representation of the organism
}

Organism::Position Organism::getPosition() {
    return {position.x, position.y};
}
