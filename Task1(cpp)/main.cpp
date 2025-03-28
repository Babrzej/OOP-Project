#include "Classes/classes.h"
#include <ctime>
#include <cstdlib>

int main() {
    std::srand(time(0));
    Human h;
    Turtle t;
    Antelope a;
    Fox f;
    Wolf w;
    Sheep s;
    std::vector<Organism*> organisms = {&h, &t, &a, &f, &w, &s};
    World world(organisms);
    world.drawWorld();
    return 0;
}