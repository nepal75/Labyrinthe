//
// Created by agaranto on 02/10/18.
//

#ifndef LABYRINTHE_LABYRINTHE_H
#define LABYRINTHE_LABYRINTHE_H
#include <stdio.h>

typedef struct {
    int largeur;
    int longueur;
    int tab[9][23];
} Labyrinthe;

void createLabyrinthe(Labyrinthe lab);
void afficherLabyrinthe(Labyrinthe lab);

#endif //LABYRINTHE_LABYRINTHE_H
