//
// Created by root on 10/10/18.
//

#include <printf.h>
#include "Menu.h"

int printMenu(){
    int choix;
    printf("Que faire ?\n (1) Créer un labyrinthe ?\n (2) Charger un labyrinthe\n (3) Jouer\n (4) Quitter\n (5) Cheat\n");
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

    //Create the labyrinthe
    Plateau *plat = malloc(sizeof(Plateau));
    assert(plat != NULL);

    plat->x = largeur;
    plat->y = longueur;
    strcpy(plat->nom,nom);

    initPlateau_0(plat);

    initPlateau_Mur(plat);

    createLabyrynthe(plat);
    addTrap(plat);
    addGifts(plat);
    afficherPlateau(plat);

    //And add it to the .cfg file
    addToFile(plat);
}

void redirect(int choix,Plateau *plateau){
    //If there is no labyrinthe loaded, plateau will be always NULL
    switch (choix){
        case 1: newLabyrinthe();
                redirect(printMenu(),plateau);
            break;
        case 2: plateau = loadLabyrinthe();
                redirect(printMenu(),plateau);
            break;
        case 3: assert(plateau!=NULL);
                jouer(plateau);
            break;
        case 4: break;
    }
}

void addToFile(Plateau *plateau){
    char str[12];
    FILE *file = NULL;
    file = fopen("/tmp/labyrinthe.cfg","a");
    assert(file != NULL);
    //Add name, width and length with a specific synthax
    fputs("/",file);
    fputs(plateau->nom,file);
    fputs(" x:",file);
    sprintf(str,"%d",plateau->x);
    fputs(str,file);
    fputs("y:",file);
    sprintf(str,"%d",plateau->y);
    fputs(str,file);
    fputs("\n",file);

    //Add all cell's values
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
        //First, find the right labyrinthe
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
    //Second, get his dimensions
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

    //Third init the labyrinthe with his dimension
    Plateau *plat = malloc(sizeof(Plateau));
    assert(plat != NULL);

    plat->x = largTab;
    plat->y = longTab;
    strcpy(plat->nom,nom);

    initPlateau_0(plat);

    //And then, catch all his cell's values
    car = fgetc(file);

    char valeur[4];

    for(int i = 0;i<plat->x;i++){
        for(int j = 0;j<plat->y;j++){
            if (car == ' ') car = fgetc(file);
            cmp = 0;
            valeur[cmp] = car;
            car = fgetc(file);
            while(car != ' ') {
                cmp++;
                valeur[cmp] = car;
                car = fgetc(file);
            }
            valeur[cmp + 1] = '\0';
            sscanf(valeur,"%d",&plat->tab[i][j]);
        }
    }

    fclose(file);
    printf("%s loaded\n", plat->nom);
    afficherPlateau(plat);

    return plat;
}

void jouer(Plateau* plateau){
    int result = 0;
    char direction;
    //Place the player at his position start
    Joueur *joueur = initJoueur();
    afficherPlateauDeJeu(plateau,joueur);
    while(result == 0){
        //Allow it to move
        viderBuffer();
        printf("Que faire ?\n (z) haut\n (q) gauche\n (s) bas\n (d) droite\n");
        scanf("%c", &direction);
        result = deplacement(plateau,joueur,direction);
    }

}

int deplacement(Plateau *plateau, Joueur *joueur, char direction){
    switch (direction){
        case 'z':
            if(joueur->x-1 > 0 &&
               plateau->tab[joueur->x -1][joueur->y] != 0){
                joueur->x --;
                joueur->score ++;
                afficherPlateauDeJeu(plateau,joueur);
                //If he walk on a gift or a trap
                if(plateau->tab[joueur->x][joueur->y] == -1){
                    printf("Vous avez marché sur un piège, moins 2 points.\n");
                    joueur->score += 2;
                    plateau->tab[joueur->x][joueur->y]=1;
                }
                else if(plateau->tab[joueur->x][joueur->y] == -2){
                    printf("Trésor récolté, + 3 points !\n");
                    joueur->score -= 3;
                    plateau->tab[joueur->x][joueur->y]=1;
                }
                printf("Score actuel : %d\n\n",joueur->score);
            }
            //Or a wall
            else printf("Deplacement impossible\n");
            break;
        case 'q':
            if(joueur->y-1 > 0 &&
               plateau->tab[joueur->x][joueur->y-1] != 0){
                joueur->y --;
                joueur->score ++;
                afficherPlateauDeJeu(plateau,joueur);
                if(plateau->tab[joueur->x][joueur->y] == -1){
                    printf("Vous avez marché sur un piège, moins 2 points.\n");
                    joueur->score += 2;
                    plateau->tab[joueur->x][joueur->y]=1;
                }
                else if(plateau->tab[joueur->x][joueur->y] == -2){
                    printf("Trésor récolté, + 3 points !\n");
                    joueur->score -= 3;
                    plateau->tab[joueur->x][joueur->y]=1;
                }
                printf("Score actuel : %d\n\n",joueur->score);
            }
            else printf("Deplacement impossible\n");
            break;
        case 's':
            if(joueur->x+1 > 0 &&
               plateau->tab[joueur->x+1][joueur->y] != 0){
                joueur->x ++;
                joueur->score ++;
                afficherPlateauDeJeu(plateau,joueur);
                if(plateau->tab[joueur->x][joueur->y] == -1){
                    printf("Vous avez marché sur un piège, moins 2 points.\n");
                    joueur->score += 2;
                    plateau->tab[joueur->x][joueur->y]=1;
                }
                else if(plateau->tab[joueur->x][joueur->y] == -2){
                    printf("Trésor récolté, + 3 points !\n");
                    joueur->score -= 3;
                    plateau->tab[joueur->x][joueur->y]=1;
                }
                printf("Score actuel : %d\n\n",joueur->score);
            }
            else printf("Deplacement impossible\n");
            break;
        case 'd':
            if(joueur->y+1 > 0 &&
               plateau->tab[joueur->x][joueur->y+1] != 0){
                joueur->y ++;
                joueur->score ++;
                afficherPlateauDeJeu(plateau,joueur);
                if(plateau->tab[joueur->x][joueur->y] == -1){
                    printf("Vous avez marché sur un piège, moins 2 points.\n");
                    joueur->score += 2;
                    plateau->tab[joueur->x][joueur->y]=1;
                }
                else if(plateau->tab[joueur->x][joueur->y] == -2){
                    printf("Trésor récolté, + 3 points !\n");
                    joueur->score -= 3;
                    plateau->tab[joueur->x][joueur->y]=1;
                }
                printf("Score actuel : %d\n\n",joueur->score);
            }
            else printf("Deplacement impossible\n");
            break;
    }
    //If he finished the labyrinthe
    if(joueur->x == plateau->x-2 &&
       joueur->y == plateau->y-1){
        printf("C'est la win !\nAvec un score de %d\nEt merceee\n",joueur->score);
        addScore(plateau,joueur->score);
        return 1;
    }
    else return 0;
}

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void addTrap(Plateau *plateau){
    //Count how many cell which are not a wall exist
    int casePassage = 0;
    for(int i = 0;i<plateau->x;i++){
        for (int j = 0;j<plateau->y;j++){
            if(plateau->tab[i][j] != 0) casePassage++;
        }
    }
    //And change 10% of them to a trap
    int nbTrap = 0;
    while(nbTrap < casePassage/10){
        int r_1 = rand()%(plateau->x - 2) + 1;
        int r_2 = rand()%(plateau->y - 2) + 1;
        if(plateau->tab[r_1][r_2] > 0){
            plateau->tab[r_1][r_2] = -1;
            nbTrap++;
        }
    }
}

void addGifts(Plateau *plateau){
    //Count how many cell which are not a wall exist
    int casePassage = 0;
    for(int i = 0;i<plateau->x;i++){
        for (int j = 0;j<plateau->y;j++){
            if(plateau->tab[i][j] != 0) casePassage++;
        }
    }
    //And change 6,66% of them to a gift
    int nbGifts = 0;
    while(nbGifts < casePassage/15){
        int r_1 = rand()%(plateau->x - 2) + 1;
        int r_2 = rand()%(plateau->y - 2) + 1;
        if(plateau->tab[r_1][r_2] > 0){
            plateau->tab[r_1][r_2] = -2;
            nbGifts++;
        }
    }

}

void addScore(Plateau *plateau,int score){
    /*FILE *file = NULL;
    file = fopen("/root/Documents/ENSICAEN/IntroProg/Labyrinthe/classique.score","a");
    assert(file != NULL);*/
}