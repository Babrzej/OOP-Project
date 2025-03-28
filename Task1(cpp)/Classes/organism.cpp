#include "organism.h"
#include <iostream>

// Default constructor
Organism::Organism(int strength, int initiative, int pX, int pY, World* world) 
    : strength(strength), initiative(initiative), pX(pX), pY(pY), world(nullptr) {}

// Destructor
Organism::~Organism() {}

// Draw method
void Organism::draw() {
    std::cout << chr; // Print the character representation of the organism
}
