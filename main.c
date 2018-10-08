#include <stdio.h>
#include "labyrinthe.h"
#include "List.h"
#include <time.h>

int main() {
    srand(time(NULL));

    Labyrinthe labyrinthe;

    Labyrinthe *lab = &labyrinthe;

    initLabyrinthe(lab,9,23);
    afficherLabyrinthe(lab);
    /*addCoordonnees(lab->list,43,42);
    addCoordonnees(lab->list,1,3);
    addCoordonnees(lab->list,4,1);*/
    printf("--------------------------------------------------------------------------------------------\n");
    createLabyrinthe(lab);
    afficherLabyrinthe(lab);
    testInitList(lab);
    /*
    afficherLabyrinthe(lab);
    createLabyrinthe(lab);*/

    return 0;
}