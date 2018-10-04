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

void testList(myList *list){
    myList *eList = NULL;
    for(eList = list;eList != NULL;eList = eList->next){
        printf("valeur : %d | x : %d | y : %d\n",eList->val,eList->allCases->x,eList->allCases->y);
    }
}

Coordonnes* addCoordonnees(myList *list,int receive,int send){
    Coordonnes* coordR = getCoordonnees(list,receive);
    Coordonnes* coordS = getCoordonnees(list,send);
    Coordonnes* listC = createCoordonees(coordR->x,coordR->y);
    listC->next = coordR;
    listC->next = coordS;
    //suppr coordS
    return listC;

}

Coordonnes* getCoordonnees(myList *list, int val){
    myList *eList = NULL;
    Coordonnes *result;
    for(eList = list;eList != NULL;eList = eList->next){
        if(eList->val == val){
            result = eList->allCases;
            break;
        }
    }
    return result;
}