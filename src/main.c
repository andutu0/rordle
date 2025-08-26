#include <stdio.h>

int main() {

    // alegem numarul de litere cu care vrem sa jucam
    int optiune = 0;
    int litere = 0;

    printf("=== Rordle ===\n");
    printf("Alege dimensiunea cuvantului:\n");
    printf("1) 4 litere\n");
    printf("2) 5 litere\n");
    printf("3) 6 litere\n");

    printf("Introdu optiunea (1-3): ");
    scanf("%d", &optiune);

    switch(optiune) {
        case 1:
            litere = 4;
            break;
        case 2:
            litere = 5;
            break;
        case 3:
            litere = 6;
            break;
        default:
            printf("Optiune invalida! Pornim default cu 5 litere.\n");
            litere = 5;
            break;
    }

    return 0;
}