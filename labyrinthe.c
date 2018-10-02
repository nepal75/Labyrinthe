//
// Created by agaranto on 02/10/18.
//

#include "labyrinthe.h"

void createLabyrinthe(Labyrinthe lab){
    //Create wall all around
    int i = 0;
    while (i != lab.longueur - 1){
        lab.tab[0][i] = 0;
        lab.tab[i][0] = 0;
        lab.tab[lab.largeur - 1][i] = 0;
        lab.tab[i][lab.longueur - 1] = 0;
        i++;
    }
    //Just now : put all other case to 1
    for(i = 1; i < lab.largeur - 1; i++){
        for(int j = 1; j < lab.longueur - 1; j++){
            lab.tab[i][j] = 1;
        }
    }
}

void afficherLabyrinthe(Labyrinthe lab){
    for(int i = 0; i < lab.largeur; i++){
        for(int j = 0; j < lab.longueur; j++){
            printf("| %d |",lab.tab[i][j]);
        }
        printf("\n");
    }
}