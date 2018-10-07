//
// Created by root on 03/10/18.
//

#ifndef LABYRINTHE_LIST_H
#define LABYRINTHE_LIST_H
#include <stdlib.h>
#include <stdio.h>

typedef struct myList List;
typedef struct Coordonnes Coord;

typedef struct {
    int x;
    int y;
    Coord * next;
} Coordonnes;

typedef struct {
    int val;
    Coordonnes *allCases;
    List * next;
} myList;

myList* createList(int val,int x, int y);
myList* addToList(int val, int x, int y,myList *list);

Coordonnes* createCoordonees(int x, int y);
Coordonnes* addToCoord(int x, int y,Coordonnes *coord);

void addCoordonnees(myList *list,int receive,int send);
Coordonnes* getCoordonnees(myList *list, int val);
void suppCoordonnees(myList *list,int val);

#endif //LABYRINTHE_LIST_H
