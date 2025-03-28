#include "human.h"

Human::Human() 
    : Animal(5, 4, nullptr) {
    chr = 'H';
    position = {1, 1};
    }