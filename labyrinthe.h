//
// Created by agaranto on 02/10/18.
//

#ifndef LABYRINTHE_LABYRINTHE_H
#define LABYRINTHE_LABYRINTHE_H
#include <stdio.h>
#include <time.h>
#include "List.h"

#define LONGUEUR 23
#define LARGEUR 9

typedef struct {
    int largeur;
    int longueur;
    int tab[LARGEUR][LONGUEUR];
    myList *list;
} Labyrinthe;

void initLabyrinthe(Labyrinthe *lab,int coord1,int coord2);
void afficherLabyrinthe(Labyrinthe *lab);
void createLabyrinthe(Labyrinthe *lab);

void addCoordonnesToList(Labyrinthe *lab,int coord1, int coord2);
void testInitList(Labyrinthe *lab);

#endif //LABYRINTHE_LABYRINTHE_H
