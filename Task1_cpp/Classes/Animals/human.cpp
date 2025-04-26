#include "human.h"
#include <conio.h>

#define STRENGTH 5
#define INITIATIVE 4
#define RANGE 1
#define SKIN '@'

#define ARROW_KEY 224
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_q 113
#define KEY_p 112
#define KEY_s 115

#define DURATION 5
#define COOLDOWN 5 + DURATION
#define POWERED_RANGE 2


Human::Human() 
    : Animal(STRENGTH, INITIATIVE, RANGE, SKIN) {
    this->duration = -1;
    this->cooldown = COOLDOWN - DURATION;
}

Human::~Human() {}

int Human::getDuration() const {
    return this->duration;
}

int Human::getCooldown() const {
    return this->cooldown;
}

void Human::setDuration(int duration) {
    this->duration = duration;
}

void Human::setCooldown(int cooldown) {
    this->cooldown = cooldown;
}

void Human::passKey(int key) {
    this->key = key;
}

void Human::action() {
    this->age++;
    this->world->freeGrid(this); 
    this->prevPosition = this->position;
    this->cooldown--;
    if(this->duration >=0) {
        this->whilePowered();
        this->duration--;
    }

    Direction direction = COUNT;

    // Map arrow keys to directions
    switch(this->key) {
        case ARROW_KEY:
        this->key = _getch();
        switch (key) {
            case KEY_UP:
                direction = UP;
                break;
            case KEY_DOWN:
                direction = DOWN;
                break;
            case KEY_LEFT:
                direction = LEFT;
                break;
            case KEY_RIGHT:
                direction = RIGHT;
                break;
        }
        break;
        case KEY_p:
            this->activatePower();
            break;
        default:
            return;
        }
        // Move the human based on the chosen direction
        switch (direction) {
            case UP:
                position.y -= this->range;
                break;
            case DOWN:
                position.y += this->range;
                break;
            case LEFT:
                position.x -= this->range;
                break;
            case RIGHT:
                position.x += this->range;
                break;
        }

        // Check if the new position is valid
        if (position.x >= 0 && position.x < world->getWidth() &&
            position.y >= 0 && position.y < world->getHeight()) {
        } else {
            // Revert to the previous position
            this->position = this->prevPosition;
        }
    }

void Human::activatePower() {
    if(this->cooldown <= 0) {
        this->duration = DURATION + 1;
        this->cooldown = COOLDOWN + 1;
        this->world->announcer.powerInfo("");
    }
    
}

void Human::whilePowered() {
    if (duration > 2) {
        this->range = POWERED_RANGE;
    } else if (duration > 0) {
        this->range = (std::rand() % POWERED_RANGE) + 1;
    }

    if (this->duration == 1) { 
        deactivatePower();
    }
}

void Human::deactivatePower() {
    this->range = 1;
    this->world->announcer.powerInfo("de");
}
