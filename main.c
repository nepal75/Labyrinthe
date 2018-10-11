#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "Tableau.h"
#include "Menu.h"

int main() {
    srand(time(NULL));

/*
    Plateau *plat = malloc(sizeof(Plateau));
    assert(plat != NULL);


    plat->x = 9;
    plat->y = 23;

    initPlateau_0(plat);

    initPlateau_Mur(plat);

    createLabyrynthe(plat);
    afficherPlateau(plat);

    Plateau plateau_2;
    Plateau *plat_2 = &plateau_2;
    plat_2->x = 9;
    plat_2->y = 23;

    initPlateau_0(plat_2);

    initPlateau_Mur(plat_2);

    createLabyrynthe(plat_2);
    afficherPlateau(plat_2);*/

    redirect(printMenu());

    return 0;
}