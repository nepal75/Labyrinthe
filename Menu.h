//
// Created by root on 10/10/18.
//

#ifndef LABYRINTHE_MENU_H
#define LABYRINTHE_MENU_H

#include <stdio.h>
#include "Tableau.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int printMenu();
void redirect(int choix, Plateau *plateau);
void newLabyrinthe();
void createFile(Plateau *plateau);
Plateau* loadLabyrinthe();
void jouer(Plateau* plateau);
int deplacement(Plateau *plateau, Joueur *joueur, char direction);
void viderBuffer();
void cheat(Plateau *plateau);
void addTrap(Plateau *plateau);
void addGifts(Plateau *plateau);
#endif //LABYRINTHE_MENU_H
