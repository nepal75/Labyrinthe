//
// Created by agaranto on 02/10/18.
//

#ifndef LABYRINTHE_LABYRINTHE_H
#define LABYRINTHE_LABYRINTHE_H
#include <stdio.h>
#include <time.h>

#define LONGUEUR 23
#define LARGEUR 9

typedef struct {
    int x;
    int y;
    struct node * next;
} Coordonnes;

typedef struct {
    int val;
    Coordonnes allCases;
    struct node * next;
} List;


typedef struct {
    int largeur;
    int longueur;
    int tab[LARGEUR][LONGUEUR];
} Labyrinthe;

void initLabyrinthe(Labyrinthe *lab);
void afficherLabyrinthe(Labyrinthe *lab);
void createLabyrinthe(Labyrinthe *lab);

#endif //LABYRINTHE_LABYRINTHE_H
