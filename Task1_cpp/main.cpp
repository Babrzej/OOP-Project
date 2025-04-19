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

    Thistle th;
    Hogweed hw;
    Guarana gu;
    Grass gr;
    Belladonna be;

    std::vector<Organism*> organisms = {&h, &t, &a, &f, &w, &s, &th, &hw, &gu, &gr, &be};
    World world(organisms);
    world.drawWorld();
    world.makeTurn();
    world.drawWorld();
    return 0;
}