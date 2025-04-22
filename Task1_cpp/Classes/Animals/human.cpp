#include "human.h"

#define STRENGTH 5
#define INITIATIVE 4
#define RANGE 1

Human::Human() 
    : Animal(STRENGTH, INITIATIVE, RANGE) {
    chr = 'H';
    position = {1, 1};
}