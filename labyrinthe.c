//
// Created by agaranto on 02/10/18.
//

#include <stdlib.h>
#include "labyrinthe.h"
#include "List.h"

void initLabyrinthe(Labyrinthe *lab,int coord1, int coord2){
    lab->largeur = coord1;
    lab->longueur = coord2;
    lab->list = NULL;

    //Put 0 (=wall) everywhere
    for (int i = 0;i<lab->largeur;i++){
        for(int j = 0; j<lab->longueur;j++){
            lab->tab[i][j] = 0;
        }
    }
    //Give value for all case except wall
    int compteur = 1;
    for(int x = 1; x < lab->largeur - 1; x++){
        if(x%2 == 1) {
            for (int y = 1; y < lab->longueur - 1; y++) {
                if(y%2 == 1) {
                    lab->tab[x][y] = compteur;
                    if(compteur == 1) lab->list = createList(1,x,y);
                    else lab->list = addToList(compteur,x,y,lab->list);
                    compteur++;
                }
            }
        }
    }
}

void afficherLabyrinthe(Labyrinthe *lab){
    for(int i = 0; i < lab->largeur; i++){
        for(int j = 0; j < lab->longueur; j++){
            int val = lab->tab[i][j];
            if(val < 10) printf("| %d|",val);
            else printf("|%d|",val);
        }
        printf("\n");
    }
}
int allCaseWasUsed(int tab[LARGEUR][LONGUEUR]){
    int response = 1;
    for (int i = 0;i<LARGEUR;i++){
        for(int j = 0;j<LONGUEUR;j++){
            if(tab[i][j] == 0){
                response = 0;
                break;
            }
        }
    }
    return response;
}

char isTherePassageAround(Labyrinthe *lab,int coord1,int coord2){
    char response = '0';
    if(lab->tab[coord1][coord2-1] == 0) response = 'l';
    else if(lab->tab[coord1][coord2+1] == 0) response = 'r';
    else if(lab->tab[coord1-1][coord2] == 0) response ='u';
    else if (lab->tab[coord1+1][coord2] == 0) response = 'd';

    return response;
}

int valuesAreSame(Labyrinthe *lab,int coord1, int coord2,char direction){
    int response = 0;
    int value = lab->tab[coord1][coord2];
    switch(direction){
        case 'l' : if(lab->tab[coord1][coord2-1] == value) response = 1;
        break;
        case 'r' : if(lab->tab[coord1][coord2+1] == value) response = 1;
        break;
        case 'u' : if(lab->tab[coord1-1][coord2] == value) response = 1;
        break;
        case 'd' : if(lab->tab[coord1+1][coord2] == value) response = 1;
        break;
    }
    return response;
}
void createLabyrinthe(Labyrinthe *lab){
    //Create an other matrice to know which case is used
    int checkTab[LARGEUR][LONGUEUR] = {0};
    while(allCaseWasUsed(checkTab) == 0){
        int random1 = rand()%(lab->largeur-2) +1;
        int random2 = rand()%(lab->longueur-2) +1;
        if (lab->tab[random1][random2] == 0){
            switch(isTherePassageAround(lab,random1,random2)){
                case 'l':
                    if(valuesAreSame(lab,random1,random2,'l') == 0){

                    }
            }
        }
    }
}


void testInitList(Labyrinthe *lab){
    myList *eList = NULL;
    for(eList = lab->list;eList != NULL;eList = eList->next){
        printf("valeur : %d | x : %d | y : %d\n",eList->val,eList->allCases->x,eList->allCases->y);
    }
}

void addCoordonnesToList(Labyrinthe *lab,int coord1, int coord2){

}