//
// Created by agaranto on 02/10/18.
//

#include "labyrinthe.h"

void createLabyrinthe(Labyrinthe labyrinthe){
    //Create wall all around
    int i = 0;
    while (i != labyrinthe.longueur - 1){
        labyrinthe.tab[0][i] = 0;
    }
}