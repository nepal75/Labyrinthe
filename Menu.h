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

/**
 * Print welcome menu
 * @return the choice of the player (create/load/play/exit)
 */
int printMenu();
/**
 * Do the right thing selon the choice on the welcome menu
 * @param choix
 * @param plateau
 */
void redirect(int choix, Plateau *plateau);
/**
 * Do something if create a labyrinthe was choose in the welcome menu
 */
void newLabyrinthe();
/**
 * Add the new labyrinthe to the .cfg file
 */
void addToFile(Plateau *plateau);
/**
 * Do something if load a labyrinthe was choose in the welcome menu
 */
Plateau* loadLabyrinthe();
/**
 * Do something if play was choose in the welcome menu
 */
void jouer(Plateau* plateau);
/**
 * Make the player moving when he is playing
 * @param plateau
 * @param joueur
 * @param direction
 * @return if the player have finished the labyrinthe
 */
int deplacement(Plateau *plateau, Joueur *joueur, char direction);
/**
 * Make the stdin's buffer for scanf()
 */
void viderBuffer();
/**
 * Test function
 * @param plateau
 */
void cheat(Plateau *plateau);
/**
 * Add some traps into the labyrinthe
 * @param plateau
 */
void addTrap(Plateau *plateau);
/**
 * Add some gifts into the labyrinthe
 * @param plateau
 */
void addGifts(Plateau *plateau);
/**
 * Add the score to the .score file
 * @param plateau
 * @param score
 */
void addScore(Plateau *plateau,int score);
#endif //LABYRINTHE_MENU_H
