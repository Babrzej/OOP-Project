#include "grass.h"

#define STRENGTH 0


Grass::Grass() 
    : Plant(STRENGTH) {
    chr = 'g';
    position = {1, 5};
}
