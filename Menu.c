//
// Created by root on 10/10/18.
//

#include "Menu.h"

int printMenu(){
    int choix;
    printf("Que faire ?\n (1) Créer un labyrinthe ?\n");
    scanf("%d",&choix);
    return choix;
}

void newLabyrinthe(){
    int largeur;
    int longueur;
    printf("Largeur ?\n");
    scanf("%d",&largeur);
    printf("Longueur ?\n");
    scanf("%d",&longueur);


    Plateau *plat = malloc(sizeof(Plateau));
    assert(plat != NULL);

    plat->x = largeur;
    plat->y = longueur;

    initPlateau_0(plat);

    initPlateau_Mur(plat);

    createLabyrynthe(plat);
    afficherPlateau(plat);
}

void redirect(int choix){
    switch (choix){
        case 1: newLabyrinthe();
            break;
    }
}
