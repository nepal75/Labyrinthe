//
// Created by root on 10/10/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Tableau.h"


void initPlateau_0(Plateau *plateau){
    plateau->tab = malloc(sizeof(*plateau->tab)*plateau->x);
    assert(plateau->tab!=NULL);
    for(int x = 0; x<plateau->x; x++){
        plateau->tab[x] = malloc(sizeof(int)*plateau->y);
        assert(plateau->tab[x]!=NULL);
    }

    for (int i = 0;i<plateau->x;i++){
        for(int j = 0; j<plateau->y;j++){
            plateau->tab[i][j] = 0;
        }
    }
}

void afficherPlateau(Plateau *plateau){
    char toPrint;
    for(int i = 0; i < plateau->x; i++){
        for(int j = 0; j < plateau->y; j++){
            int val = plateau->tab[i][j];
            if(val != 0) printf("  ");
            else printf("# ");
        }
        printf("\n");
    }
    printf("\n\n");
}


void initPlateau_Mur(Plateau *plateau){
    int compteur = 1;
    for(int i = 0;i<plateau->x;i++){
        if(i%2 == 1){
            for(int j = 0;j<plateau->y;j++){
                if(j%2 == 1){
                    plateau->tab[i][j] = compteur;
                    compteur++;
                }
            }
        }
    }
}


void createLabyrynthe(Plateau *plateau){
    int **tabTest;

    tabTest = malloc(sizeof(*tabTest)*plateau->x);
    assert(tabTest!=NULL);
    for(int x = 0; x<plateau->x; x++){
        tabTest[x] = malloc(sizeof(int)*plateau->y);
        assert(tabTest[x]!=NULL);
    }

    for (int i = 0;i<plateau->x;i++){
        for(int j = 0; j<plateau->y;j++){
            tabTest[i][j] = 0;
        }
    }

    while(ifAllValueProcessed(plateau->x,plateau->y,tabTest)) {
        int r_1 = rand()%(plateau->x - 2) + 1;
        int r_2 = rand()%(plateau->y - 2) + 1;
        //check the cell randomly choose is a wall
        if (plateau->tab[r_1][r_2] == 0) {
            //check the upside cell is not a wall
            if (plateau->tab[r_1 - 1][r_2] != 0) {
                //check the downside cell is not a wall
                if (plateau->tab[r_1 + 1][r_2] != 0 && plateau->tab[r_1 + 1][r_2] != plateau->tab[r_1 - 1][r_2]) {
                    plateau->tab[r_1][r_2] = plateau->tab[r_1 - 1][r_2];
                    changeValue(plateau, plateau->tab[r_1 - 1][r_2], plateau->tab[r_1 + 1][r_2]);

                    tabTest[r_1][r_2] = 1;
                    continue;
                }
            }
            //if the leftside cell is not a wall
            if (plateau->tab[r_1][r_2 - 1] != 0){
                //if the rigthside cell is not a wall
                if(plateau->tab[r_1][r_2 + 1] != 0 && plateau->tab[r_1][r_2 + 1] != plateau->tab[r_1][r_2 - 1]){
                    plateau->tab[r_1][r_2] = plateau->tab[r_1][r_2 - 1];
                    changeValue(plateau,plateau->tab[r_1][r_2 - 1],plateau->tab[r_1][r_2 + 1]);
                }
            }
        }
        tabTest[r_1][r_2] = 1;
    }
    addEntryExit(plateau);
}


void changeValue(Plateau *plateau, int valueFrom, int valueTo){
    for(int i = 0; i<plateau->x;i++){
        for(int j = 0;j<plateau->y;j++){
            if(plateau->tab[i][j] == valueFrom) plateau->tab[i][j] = valueTo;
        }
    }
}

int ifAllValueProcessed(int x, int y,int **tab){
    for(int i = 1;i<x-1;i++){
        for(int j = 1;j<y-1;j++){
            if(tab[i][j] == 0) return 1;
        }
    }
    return 0;
}


void addEntryExit(Plateau *plateau){
    plateau->tab[1][0] = 1;
    plateau->tab[plateau->x-2][plateau->y-1] = 1;
}

Joueur* initJoueur(){
    Joueur *joueur = malloc(sizeof(Joueur));
    assert(joueur != NULL);

    joueur->x = 1;
    joueur->y = 0;
}

void afficherPlateauDeJeu(Plateau *plateau,Joueur *joueur){
    char toPrint;
    for(int i = 0; i < plateau->x; i++){
        for(int j = 0; j < plateau->y; j++){
            if(i == joueur->x && j == joueur->y){
                printf("o ");
            }
            else{
                int val = plateau->tab[i][j];
                if(val != 0) printf("  ");
                else printf("# ");
            }
        }
        printf("\n");
    }
    printf("\n\n");
}