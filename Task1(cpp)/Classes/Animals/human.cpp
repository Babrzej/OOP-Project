#include "human.h"

#define STRENGTH 5
#define INITIATIVE 4
Human::Human() 
    : Animal(STRENGTH, INITIATIVE) {
    chr = 'H';
    position = {1, 1};
}