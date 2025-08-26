#include <stdio.h>
#include "game.h"
#include "utils.h"

void get_word(int word_length, char *word)
{
    FILE *file;

    if (word_length == 4) {
        file = fopen("wordlists/words4_unique.txt", "r");
    } else if (word_length == 5) {
        file = fopen("wordlists/words5_unique.txt", "r");
    } else {
        file = fopen("wordlists/words6_unique.txt", "r");
    }

    // verificam daca am reusit sa deschidem wordlistul
    if (file == NULL) {
        perror("Error opening word list file");
        return;
    }

    // obtinem un cuvant random din wordlistul deschis
    get_random_word(file, word_length, word);
    fclose(file);
}

void game_4_letters(char *word)
{
    printf("\n\n\n\n\n");
    printf("=======================\n\n");
}

void game_5_letters(char *word)
{
    printf("\n\n\n\n\n");
    printf("=======================\n\n");
}

void game_6_letters(char *word)
{
    printf("\n\n\n\n\n");
    printf("=======================\n\n");
}

void start_game(int word_length)
{
    char *word = malloc(word_length + 1);
    if (word == NULL) {
        perror("Error allocating memory for word");
        return;
    }

    get_word(word_length, word);

    

    free(word);
}

