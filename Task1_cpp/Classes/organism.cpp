#include "organism.h"
#include "world.h"
#include <iostream>

// Default constructor
Organism::Organism(int strength, int initiative) 
    : strength(strength), initiative(initiative), world(nullptr), alive(true), age(10) {}

// Destructor
Organism::~Organism() {}

void Organism::setWorld(World* world) {
    this->world = world;
}

void Organism::draw() {
    std::cout << skin;
}

void Organism::die() {
    this->alive = false;
    this->world->freeGrid(this);
    this->world->announcer.killInfo(this);
}
bool Organism::isDead() {
    if(!this->alive) return true;
    return false;
}

Position Organism::getRandomValidPosition() {
    while(true) {
        int x = std::rand() % this->world->getWidth();
        int y = std::rand() % this->world->getHeight();
        Position newPos = {x, y};
        if(!this->world->isGridOccupied(newPos)) {
            return newPos;
        }
    }
}

// Getters
int Organism::getStrength() const {
    return strength;
}

int Organism::getInitiative() const {
    return initiative;
}

int Organism::getAge() const {
    return age;
}

Position Organism::getPosition() const {
    return position;
}

Position Organism::getPrevPosition() const {
    return prevPosition;
}

// Setters
void Organism::setStrength(int strength) {
    this->strength = strength;
}

void Organism::setInitiative(int initiative) {
    this->initiative = initiative;
}

void Organism::setAge(int age) {
    this->age = age;
}

void Organism::setPosition(const Position& position) {
    this->position = position;
}







