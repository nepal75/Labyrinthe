//
// Created by root on 10/10/18.
//

#ifndef LABYRINTHE_TABLEAU_H
#define LABYRINTHE_TABLEAU_H

#include <time.h>

/**
 * A plateau is a labyrinthe, x is the width, y longer, tab is constitution
 * nom his name
 */
typedef struct {
    int x;
    int y;
    int **tab;
    char nom[10];
} Plateau;

/**
 * A player is define by his position x and y ans his score
 */
typedef struct {
    int x;
    int y;
    int score;
} Joueur;

/**
 * Initialize each cell to 0
 */
void initPlateau_0(Plateau *plateau);
/**
 * Print the labyrinthe
 * @param plateau
 */
void afficherPlateau(Plateau *plateau);
/**
 * Init labyrinthe's wall
 * @param plateau
 */
void initPlateau_Mur(Plateau *plateau);
/**
 * Break walls and add gifts ans trap to the final labyrinthe
 * @param plateau
 */
void createLabyrynthe(Plateau *plateau);
/**
 * Convert all cells of the labyrinthe with a specific value to an other one
 * @param plateau
 * @param valueFrom
 * @param valueTo
 */
void changeValue(Plateau *plateau, int valueFrom, int valueTo);
/**
 * Check if every cells was processed
 * @param x
 * @param y
 * @param tab
 * @return
 */
int ifAllValueProcessed(int x, int y,int **tab);
/**
 * Add the entry and the exit of the labyrinthe
 * @param plateau
 */
void addEntryExit(Plateau *plateau);
/**
 * Print the labyrinthe with the player position when he is playing
 * @param plateau
 * @param joueur
 */
void afficherPlateauDeJeu(Plateau *plateau,Joueur *joueur);
/**
 * creturn a new player
 * @return
 */
Joueur* initJoueur();

#endif //LABYRINTHE_TABLEAU_H