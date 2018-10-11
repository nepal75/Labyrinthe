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
int allCaseWasUsed(int largeur, int longueur, int tab[largeur][longueur]);
void loadTab(Labyrinthe *lab,int val);
void testInitList(Labyrinthe *lab);
char isThereValueArroundThisWall(char ref,Labyrinthe *lab,int x, int y, int val);
void addSecondCheck(char refSecond,int x, int y,Labyrinthe *lab,int val);

#endif //LABYRINTHE_LABYRINTHE_H
