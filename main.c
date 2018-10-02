#include <stdio.h>
#include "labyrinthe.h"

int main() {
    Labyrinthe labyrinthe;
    labyrinthe.largeur = 9;
    labyrinthe.longueur = 23;
    createLabyrinthe(labyrinthe);
    afficherLabyrinthe(labyrinthe);
    return 0;
}