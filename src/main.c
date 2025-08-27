#include <stdio.h>
#include "game.h"

int main() {

    // alegem numarul de litere cu care vrem sa jucam
    int option = 0;
    int number_of_letters = 0;

    printf("=== Rordle ===\n\n");
    printf("Alege dimensiunea cuvantului:\n\n");
    printf("1) 4 litere\n");
    printf("2) 5 litere\n");
    printf("3) 6 litere\n\n");

    printf("Introdu optiunea (1-3): ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            number_of_letters = 4;
            break;
        case 2:
            number_of_letters = 5;
            break;
        case 3:
            number_of_letters = 6;
            break;
        default:
            printf("Optiune invalida! Pornim default cu 5 litere.\n\n");
            number_of_letters = 5;
            break;
    }

    printf("Pornim jocul cu %d litere.\n", number_of_letters);
    start_game(number_of_letters);

    return 0;
}