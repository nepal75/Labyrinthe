#include <stdio.h>
#include "labyrinthe.h"
#include "List.h"
#include <time.h>

int main() {
    Labyrinthe labyrinthe;

    Labyrinthe *lab = &labyrinthe;

    initLabyrinthe(lab,9,23);
    testInitList(lab);
    addCoordonnees(lab->list,43,42);
    addCoordonnees(lab->list,1,3);
    addCoordonnees(lab->list,4,1);
    printf("-----------------------------------\n"),
    testInitList(lab);
    /*
    afficherLabyrinthe(lab);
    createLabyrinthe(lab);*/

    return 0;
}