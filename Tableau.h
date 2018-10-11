//
// Created by root on 10/10/18.
//

#ifndef LABYRINTHE_TABLEAU_H
#define LABYRINTHE_TABLEAU_H

#include <time.h>


typedef struct {
    int x;
    int y;
    int **tab;
} Plateau;

//Initialize each cell to 0
void initPlateau_0(Plateau *plateau);
//print plateau
void afficherPlateau(Plateau *plateau);
//Put the first value
void initPlateau_Mur(Plateau *plateau);
//Create the labyrinthe
void createLabyrynthe(Plateau *plateau);
//Change value of all cell with one specific value
void changeValue(Plateau *plateau, int valueFrom, int valueTo);
//Check if all cell was process
int ifAllValueProcessed(int x, int y,int **tab);
//Add entry and exit
void addEntryExit(Plateau *plateau);

#endif //LABYRINTHE_TABLEAU_H