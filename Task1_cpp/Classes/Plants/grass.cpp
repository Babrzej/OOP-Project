#include "grass.h"

#define STRENGTH 0
#define SKIN 'g'

Grass::Grass() 
    : Plant(STRENGTH, SKIN) {
    position = {1, 5};
}
