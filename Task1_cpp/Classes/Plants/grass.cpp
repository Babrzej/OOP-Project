#include "grass.h"

#define STRENGTH 0


Grass::Grass() 
    : Plant(STRENGTH) {
    chr = 'g';
    _position = {1, 5};
}
