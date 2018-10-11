//
// Created by root on 03/10/18.
//
#include "List.h"

myList* createList(int val, int x, int y) {
    Coordonnes *coord = createCoordonees(x,y);

    myList *list = malloc(sizeof(list));
    list->val = val;
    list->allCases = coord;
    list->next = NULL;

    return list;
}

Coordonnes* createCoordonees(int x, int y){
    Coordonnes *coord = malloc(sizeof(coord));
    coord->x = x;
    coord->y = y;
    coord->next = NULL;

    return coord;
}

Coordonnes* addToCoord(int x, int y,Coordonnes *coord){
    Coordonnes* newCoord = createCoordonees(x,y);
    newCoord->next = coord;
    return newCoord;
}

myList* addToList(int val, int x, int y, myList *list){
    myList* newList = createList(val,x,y);
    newList->next = list;
    return newList;
}

void addCoordonnees(myList *list,int receive,int send){
    Coordonnes* coordS = getCoordonnees(list,send);

    for(list ;list != NULL;list = list->next) {
        if(list->val == receive){
            list->allCases->next = coordS;
            break;
        }
    }
    suppCoordonnees(list,send);
}

Coordonnes* getCoordonnees(myList *list, int val){
    Coordonnes *result;
    for(list;list != NULL;list = list->next){
        if(list->val == val){
            result = list->allCases;
            break;
        }
    }
    return result;
}


void suppCoordonnees(myList *list,int val){
    for(list;list != NULL;list = list->next){
        if(list->val == val){
            list->val = 0;
            break;
        }
    }
}

int allCaseUsed(myList* list){
    int compteur = 0;
    int result = 0;
    for(list;list!=NULL;list=list->next){
        if(list->val != 0) compteur++;
    }
    if (compteur == 1) result = 1;
    return result;
}

void addOneCoordonnee(myList *list,int val, int x, int y){
    for(list;list!=NULL;list = list->next){
        if(list->val == val){
            Coordonnes *c = createCoordonees(x,y);
            c->next = list->allCases->next;
            list->allCases->next = c;
            return;
        }
    }
}