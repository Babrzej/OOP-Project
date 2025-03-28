#include "fox.h"

#define STRENGTH 3
#define INITIATIVE 7

Fox::Fox() 
    : Animal(STRENGTH, INITIATIVE) {
    chr = 'F';
    position = {4, 4};
}