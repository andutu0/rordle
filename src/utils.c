#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"

char *get_random_word(FILE *file, int word_length, char *buffer) {
    if (file == NULL || buffer == NULL || word_length <= 0) {
        return NULL;
    }

    // numaram cuvintele
    int total_words = 0;
    char temp[512];

    while (fgets(temp, sizeof(temp), file) != NULL) {
        total_words++;
    }

    if (total_words == 0) {
        return NULL;
    }

    // alegem un numar random
    srand((unsigned int)time(NULL));
    int index = rand() % total_words;

    // mergem la linia random
    rewind(file);
    for (int i = 0; i < index; i++) {
        if (fgets(temp, sizeof(temp), file) == NULL) {
            return NULL;
        }
    }

    // citim cuvantul
    if (fgets(buffer, word_length + 16, file) != NULL) {
        // stergem newline ul
        buffer[strcspn(buffer, "\r\n")] = '\0';
        return buffer;
    }

    return NULL;
}

void print_checked_word(const char *word, const char *guess) {
    for (int i = 0; i < strlen(word); i++) {
        if (guess[i] == word[i]) {
            // litera corecta si la locul ei
            printf("[%c] ", guess[i]);
        } else if (strchr(word, guess[i]) != NULL) {
            // litera corecta dar la locul gresit
            printf("(%c) ", guess[i]);
        } else {
            // litera gresita
            printf("%c ", guess[i]);
        }
    }
    printf("\n");
}