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
    allCaseWasUsed(LARGEUR,LONGUEUR,tab);
    while(allCaseWasUsed(LARGEUR,LONGUEUR,tab) == 0){
        int random1 = rand()%(lab->largeur-2) +1;
        int random2 = rand()%(lab->longueur-2) +1;

        if (lab->tab[random1][random2] == 0){
            switch(isTherePassageAround(lab,random1,random2)){
                case 'l':
                    if(valuesAreSame(lab,random1,random2,'l') == 0){
                        int valueR = lab->tab[random1][random2];
                        int valueS = lab->tab[random1][random2-1];
                        addCoordonnees(lab->list,valueR,valueS);
                    }
                    tab[random1][random2] = 1;
                    break;
                case 'r':
                    if(valuesAreSame(lab,random1,random2,'r') == 0){
                        int valueR = lab->tab[random1][random2];
                        int valueS = lab->tab[random1][random2+1];
                        addCoordonnees(lab->list,valueR,valueS);
                    }
                    tab[random1][random2] = 1;
                    break;
                case 'u':
                    if(valuesAreSame(lab,random1,random2,'u') == 0){
                        int valueR = lab->tab[random1][random2];
                        int valueS = lab->tab[random1-1][random2];
                        printf("before\n");
                        Coordonnes *c = getCoordonnees(lab->list,valueR);
                        for(c;c!=NULL;c = c->next){
                            printf("x : %d y : %d\n",c->x,c->y);
                        }

                        addCoordonnees(lab->list,valueR,valueS);

                        Coordonnes *c2 = getCoordonnees(lab->list,valueR);
                        printf("after\n");
                        for(c2;c2!=NULL;c2 = c2->next){
                            printf("x : %d y : %d\n",c2->x,c2->y);
                        }
                    }
                    tab[random1][random2] = 1;
                    break;
                case 'd':
                    printf("%d\n",valuesAreSame(lab,random1,random2,'d'));
                    if(valuesAreSame(lab,random1,random2,'d') == 0){
                        int valueR = lab->tab[random1][random2];
                        int valueS = lab->tab[random1+1][random2];
                        Coordonnes *c = getCoordonnees(lab->list,valueR);
                        printf("Bite\n");
                        while(c->next!=NULL){
                            printf("x : %d y : %d\n",c->x,c->y);
                            c = c->next;
                        }
                        addCoordonnees(lab->list,valueR,valueS);
                        c = getCoordonnees(lab->list,valueR);
                        while(c->next!=NULL){
                            printf("x : %d y : %d\n",c->x,c->y);
                            c = c->next;
                        }
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

void loadTab(Labyrinthe *lab){
    for(lab->list;lab->list!=NULL;lab->list = lab->list->next){
        while(lab->list->allCases->next != NULL){
            lab->tab[lab->list->allCases->x][lab->list->allCases->y] = lab->list->val;
            lab->list->allCases = lab->list->allCases->next;
        }
    }
}