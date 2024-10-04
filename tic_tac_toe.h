#include <stdlib.h>
#include <stdio.h>


void printtable(char table[]) {
    printf(" %c | %c | %c \n", table[0], table[1], table[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", table[3], table[4], table[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", table[6], table[7], table[8]);
}

void coup(int tabcoup[], char table[]) {
    int choix;
    printf("Faites votre coup (0-8) : ");
    scanf("%d", &choix);
    if (choix >= 0 && choix <= 8 && table[choix] == ' ') {
        tabcoup[choix] = 1;
        table[choix] = 'X';
    } else {
        printf("Mouvement invalide. Essayez encore.\n");
        coup(tabcoup, table);
    }
}

void coupadverse(int tabcoup[], char table[]) {
    int coupadv;
    do {
        coupadv = rand() % 9;
    } while (table[coupadv] != ' ');
    tabcoup[coupadv] = 2;
    table[coupadv] = 'O';
}

int winloss(int tabcoup[]) {
    int win_conditions[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, 
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, 
        {0, 4, 8}, {2, 4, 6}             
    };
    for (int i = 0; i < 8; i++) {
        if (tabcoup[win_conditions[i][0]] == 1 && tabcoup[win_conditions[i][1]] == 1 && tabcoup[win_conditions[i][2]] == 1) {
            printf("Vous avez gagné !\n");
            return 1;
        }
        if (tabcoup[win_conditions[i][0]] == 2 && tabcoup[win_conditions[i][1]] == 2 && tabcoup[win_conditions[i][2]] == 2) {
            printf("La machine a gagné !\n");
            return 1;
        }
    }
    return 0;
}