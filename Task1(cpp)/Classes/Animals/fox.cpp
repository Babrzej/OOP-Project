#include "fox.h"
#include "../world.h"

#define STRENGTH 3
#define INITIATIVE 7

Fox::Fox() 
    : Animal(STRENGTH, INITIATIVE) {
    chr = 'F';
    position = {4, 4};
}

// void Fox::action() {
//     Position prevPos = this->getPosition();
//     World* w = this->world;
//     bool done = false;
//     while(!done) {
//         Animal::action();
//         done = true;
//         for(Organism* organism : w->getOrganisms()) {
//             if( organism->getPosition().x == this->getPosition().x &&
//                 organism->getPosition().y == this->getPosition().y) {
//                 this->moveBack();
//                 done = false;
//             }
//         }
//     }
// }
