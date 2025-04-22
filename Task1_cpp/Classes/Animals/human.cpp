#include "human.h"
#include <conio.h>

#define STRENGTH 5
#define INITIATIVE 4
#define RANGE 1
#define SKIN 'P'

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_q 113

Human::Human() 
    : Animal(STRENGTH, INITIATIVE, RANGE, SKIN) {
    position = {1, 1};
}

void Human::action() {

    this->world->freeGrid(this); // Free the previous grid cell
    this->prevPosition = this->position;

    bool validMove = false;
    while (!validMove) {
        int key = _getch(); // Get the first key press
        Direction direction = COUNT;

        // Map arrow keys to directions
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
            case KEY_q:
                this->die();
            default:
                return; // Exit if an invalid key is pressed
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
            validMove = true; // Exit the loop if the move is valid
        } else {
            // Revert to the previous position and retry
            this->position = this->prevPosition;
        }
    }
    //this->world->announcer.moveInfo(this); // Announce the move
}
