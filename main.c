#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "tic_tac_toe.h"


int main() {
    char table[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int tabcoup[9] = {0};
    srand(time(NULL));

    printf("Bienvenue dans ce Tic-Tac-Toe !\n");
    printtable(table);

    for (int i = 0; i < 9; i++) {
        if (i % 2 == 0) {
            coup(tabcoup, table);
        } else {
            coupadverse(tabcoup, table);
        }
        printtable(table);

        if (winloss(tabcoup)) {
            break;
        }
    }

    if (!winloss(tabcoup)) {
        printf("Match nul !\n");
    }
	
    return 0;
}