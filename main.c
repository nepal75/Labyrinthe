#include <stdio.h>
#include "labyrinthe.h"
#include "List.h"
#include <time.h>

int main() {
    Labyrinthe labyrinthe;

    Labyrinthe *lab = &labyrinthe;

    initLabyrinthe(lab,9,23);
    testInitList(lab);
    addCoordonnees(lab,1,2),
    printf("-----------------------------------\n"),
    testInitList(lab);
    /*
    afficherLabyrinthe(lab);
    createLabyrinthe(lab);*/

    return 0;
}