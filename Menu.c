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
    char nom[10] = {0};
    printf("Largeur ?\n");
    scanf("%d",&largeur);
    printf("Longueur ?\n");
    scanf("%d",&longueur);
    printf("Quel nom lui donner ?(10 carac max)\n");
    scanf("%s",&nom);


    Plateau *plat = malloc(sizeof(Plateau));
    assert(plat != NULL);

    plat->x = largeur;
    plat->y = longueur;
    strcpy(plat->nom,nom);

    initPlateau_0(plat);

    initPlateau_Mur(plat);

    createLabyrynthe(plat);
    afficherPlateau(plat);
    createFile(plat);
}

void redirect(int choix){
    switch (choix){
        case 1: newLabyrinthe();
            break;
    }
}

void createFile(Plateau *plateau){
    char str[12];
    FILE *file = NULL;
    file = fopen("/tmp/labyrinthe.cfg","a");
    assert(file != NULL);
    fputs("Labyrinthe : ",file);
    fputs(plateau->nom,file);
    fputs("\n",file);

    for(int i = 0;i<plateau->x;i++){
        for(int j=0;j<plateau->y;j++){
            sprintf(str,"%d",plateau->tab[i][j]);
            fputs(str,file);
        }
    }
    fputs("\n",file);
    fclose(file);
}
