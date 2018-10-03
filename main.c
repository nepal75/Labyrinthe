#include <stdio.h>
#include "labyrinthe.h"
#include <time.h>

int main() {
    Labyrinthe labyrinthe;
    labyrinthe.largeur = 9;
    labyrinthe.longueur = 23;

    Labyrinthe *lab = &labyrinthe;

    initLabyrinthe(lab);
    afficherLabyrinthe(lab);
    //createLabyrinthe(lab);
    return 0;
}