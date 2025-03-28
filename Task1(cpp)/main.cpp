#include "Classes/classes.h"

int main() {
    Human h;
    std::vector<Organism*> organisms;
    organisms.push_back(&h);
    World w(organisms);
    w.drawWorld();
    return 0;
}