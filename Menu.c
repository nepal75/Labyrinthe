//
// Created by root on 10/10/18.
//

#include "Menu.h"

int printMenu(){
    int choix;
    printf("Que faire ?\n (1) Créer un labyrinthe ?\n (2) Charger un labyrinthe\n");
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
                redirect(printMenu());
            break;
        case 2: loadLabyrinthe();
                redirect(printMenu());
            break;
    }
}

void createFile(Plateau *plateau){
    char str[12];
    FILE *file = NULL;
    file = fopen("/tmp/labyrinthe.cfg","a");
    assert(file != NULL);
    fputs("/",file);
    fputs(plateau->nom,file);
    fputs(" x:",file);
    sprintf(str,"%d",plateau->x);
    fputs(str,file);
    fputs("y:",file);
    sprintf(str,"%d",plateau->y);
    fputs(str,file);
    fputs("\n",file);

    for(int i = 0;i<plateau->x;i++){
        for(int j=0;j<plateau->y;j++){
            sprintf(str,"%d",plateau->tab[i][j]);
            fputs(str,file);
            fputs(" ",file);
        }
    }
    fputs("\n",file);
    fclose(file);
}

Plateau* loadLabyrinthe(){
    char nom[10] = {0};
    printf("Quel labyrinthe charger ?\n");
    scanf("%s",&nom);
    char car = 'i';
    int cmp = 0;
    char nom_2[10] = {0};

    FILE *file = NULL;
    file = fopen("/tmp/labyrinthe.cfg","r");
    assert(file!=NULL);
    while(car != EOF){
        car = fgetc(file);
        if(car == '/'){
            car = fgetc(file);
            while(car != ' '){
                nom_2[cmp] = car;
                cmp++;
                car = fgetc(file);
            }
            if(strcmp(nom_2,nom) == 0) break;
            else{
                for(int i = 0; i<10;i++){
                    nom_2[i] = '\0';
                }
                cmp = 0;
            }
        }
    }
    car = fgetc(file);
    car = fgetc(file);
    car = fgetc(file);

    char largeurL[3];
    char longueurL[3];
    cmp = 0;

    while(car != '\n'){
        while(car != 'y'){
            largeurL[cmp] = car;
            cmp++;
            car = fgetc(file);
        }
        car = fgetc(file);
        cmp = 0;

        car = fgetc(file);
        while(car != '\n'){
            longueurL[cmp] = car;
            cmp++;
            car = fgetc(file);
        }
    }
    int longTab;
    int largTab;
    sscanf(largeurL,"%d",&largTab);
    sscanf(longueurL,"%d",&longTab);

    Plateau *plat = malloc(sizeof(Plateau));
    assert(plat != NULL);

    plat->x = largTab;
    plat->y = longTab;
    strcpy(plat->nom,nom);

    initPlateau_0(plat);

    car = fgetc(file);

    char valeur[3];

    for(int i = 0;i<plat->x;i++){
        for(int j = 0;j<plat->y;j++){
            if (car == ' ') car = fgetc(file);
            cmp = 0;
            valeur[cmp] = car;
            car = fgetc(file);
            if(car != ' ') {
                cmp++;
                valeur[cmp] = car;
                car = fgetc(file);
            }
            else valeur[cmp + 1] = 0;
            sscanf(valeur,"%d",&plat->tab[i][j]);
        }
    }

    fclose(file);
    printf("%s loaded : x = %d y = %d\n", plat->nom,plat->x, plat->y);
    afficherPlateau(plat);

    return plat;
}
