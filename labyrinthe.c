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
int allCaseWasUsed(int largeur, int longueur, int tab[largeur][longueur]){
    int i = 1;
    int j = 1;/*
    for(int x = 0;x<largeur;x++){
        for(int y = 0;y<longueur;y++){
            printf("|%d|",tab[x][y]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;*/
    for(i;i<largeur-1;i++){
        for(j;j<longueur-1;j++){
            if(tab[i][j] == 0) return 0;
        }
    }
    return 1;
    //eturn allCaseUsed(labyrinthe->list);
}

char isTherePassageAround(Labyrinthe *lab,int coord1,int coord2){
    char response = '0';
    if(lab->tab[coord1][coord2-1] != 0) response = 'l';
    else if(lab->tab[coord1][coord2+1] != 0) response = 'r';
    else if(lab->tab[coord1-1][coord2] != 0) response ='u';
    else if (lab->tab[coord1+1][coord2] != 0) response = 'd';

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
        default:response = 0;
    }
    return response;
}

void createLabyrinthe(Labyrinthe *lab){
    int tab[LARGEUR][LONGUEUR] = {0};
    int tabRandom[LARGEUR][LONGUEUR] = {0};
    allCaseWasUsed(LARGEUR,LONGUEUR,tab);
    while(allCaseWasUsed(LARGEUR,LONGUEUR,tab) == 0){

        int random1 = rand()%(LARGEUR-2)+1;
        int random2 = rand()%(LONGUEUR-2)+1;

        tabRandom[random1][random2] = 1;

        int valueR = lab->tab[random1][random2];
        int valueS;
        char secondCheck;

        if (valueR == 0){
            switch(isTherePassageAround(lab,random1,random2)){
                case 'l':
                        valueS = lab->tab[random1][random2-1];
                        secondCheck = isThereValueArroundThisWall('l',lab,random1,random2,valueS);
                        if(secondCheck != 'o'){
                            addOneCoordonnee(lab->list,valueS,random1,random2);
                            lab->tab[random1][random2] = valueS;
                            addSecondCheck(secondCheck,random1,random2,lab,valueS);
                        }

                        tab[random1][random2] = 1;
                        break;
                case 'r':
                        valueS = lab->tab[random1][random2+1];
                        secondCheck = isThereValueArroundThisWall('r',lab,random1,random2,valueS);
                        if(secondCheck != 'o'){
                            addOneCoordonnee(lab->list,valueS,random1,random2);
                            lab->tab[random1][random2] = valueS;
                            addSecondCheck(secondCheck,random1,random2,lab,valueS);
                        }

                        tab[random1][random2] = 1;
                        break;
                case 'u':
                        valueS = lab->tab[random1-1][random2];
                        secondCheck = isThereValueArroundThisWall('u',lab,random1,random2,valueS);
                        if(secondCheck != 'o'){
                            addOneCoordonnee(lab->list,valueS,random1,random2);
                            lab->tab[random1][random2] = valueS;
                            addSecondCheck(secondCheck,random1,random2,lab,valueS);
                        }

                        tab[random1][random2] = 1;
                        break;
                case 'd':
                        valueS = lab->tab[random1+1][random2];
                        secondCheck = isThereValueArroundThisWall('d',lab,random1,random2,valueS);
                        if(secondCheck != 'o'){
                            addOneCoordonnee(lab->list,valueS,random1,random2);
                            lab->tab[random1][random2] = valueS;
                            addSecondCheck(secondCheck,random1,random2,lab,valueS);
                        }

                        tab[random1][random2] = 1;
                        break;
                default: tab[random1][random2] = 1;
            }
        }
        else tab[random1][random2] = 1;
    }
}

void testInitList(Labyrinthe *lab){
    myList *eList = NULL;
    for(eList = lab->list;eList != NULL;eList = eList->next) {
        Coordonnes *cList = eList->allCases;
        while (cList) {
            printf("valeur : %d | x : %d | y : %d\n", eList->val, cList->x, cList->y);
            cList = cList->next;
        }
    }
}

void loadTab(Labyrinthe *lab,int val){
    int x;
    int y;
    for(lab->list;lab->list!=NULL;lab->list = lab->list->next){
        if (lab->list->val == val) {
            while (lab->list->allCases->next != NULL && x > -1 && y > -1) {
                x = lab->list->allCases->x;
                y = lab->list->allCases->y;
                if (x > -1 && y > -1) {
                    lab->tab[x][y] = lab->list->val;
                    lab->list->allCases = lab->list->allCases->next;
                }
            }
        }
    }
}

char isThereValueArroundThisWall(char ref,Labyrinthe *lab,int x, int y, int val){
    char result = 'o';
    switch (ref){
        case 'l':
            if(lab->tab[x][y+1] != 0 && lab->tab[x][y+1] != val) return 'r';
            break;
        case 'r':
            if(lab->tab[x][y-1] != 0 && lab->tab[x][y-1] != val) return 'l';
            break;
        case 'u': if(lab->tab[x+1][y] != 0 && lab->tab[x+1][y] != val) return 'd';
            break;
        case 'd': if(lab->tab[x-1][y] != 0 && lab->tab[x-1][y] != val) return 'u';
            break;
        default: return 'o';
    }
    return result;
}

void addSecondCheck(char refSecond,int x, int y,Labyrinthe *lab,int val){
    switch (refSecond){
        case 'r':
            addCoordonnees(lab->list,lab->tab[x][y],lab->tab[x][y+1]);
            lab->tab[x][y+1] = val;
            loadTab(lab,val);
            break;
        case 'l':
            addCoordonnees(lab->list,lab->tab[x][y],lab->tab[x][y-1]);
            lab->tab[x][y-1] = val;
            loadTab(lab,val);
            break;
        case 'u':
            addCoordonnees(lab->list,lab->tab[x][y],lab->tab[x-1][y]);
            lab->tab[x-1][y] = val;
            loadTab(lab,val);
            break;
        case 'd':
            addCoordonnees(lab->list,lab->tab[x][y],lab->tab[x+1][y]);
            lab->tab[x+1][y] = val;
            loadTab(lab,val);
            break;
        default:break;
    }

    printf("value : %d\n",val);
    afficherLabyrinthe(lab);
    printf("\n");
}