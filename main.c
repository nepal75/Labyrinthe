#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "Tableau.h"
#include "Menu.h"

int main() {
    srand(time(NULL));
    Plateau *plateau = NULL;
    redirect(printMenu(),plateau);

    return 0;
}