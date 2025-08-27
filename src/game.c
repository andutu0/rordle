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
    int guess_count = 0;
    char guess[5];
    char previous_guesses[4][5];

    printf("=======================\n\n");

    while (guess_count <= 4) {
        switch (guess_count) {
            case 0:
                for (int i = 0; i < 4; i++)
                    printf("_ _ _ _\n");

                // citim o noua incercare
                printf("\nCuvântul este: ");
                if (scanf("%5s", guess) != 1) {
                    printf("Eroare la citirea cuvântului.\n");
                    return;
                }
                guess[4] = '\0';

                if (strcmp(guess, word) == 0) {
                    printf("Felicitări! Ai ghicit cuvântul %s!\n", word);
                    return;
                } else {
                    strcpy(previous_guesses[0], guess);
                }
                printf("\n");
                break;

            case 1:
                print_checked_word(word, previous_guesses[0]);

                for (int i = 0; i < 3; i++)
                    printf("_ _ _ _\n");
                
                // citim o noua incercare
                printf("\nCuvântul este: ");
                if (scanf("%5s", guess) != 1) {
                    printf("Eroare la citirea cuvântului.\n");
                    return;
                }
                guess[4] = '\0';

                if (strcmp(guess, word) == 0) {
                    printf("Felicitări! Ai ghicit cuvântul %s!\n", word);
                    return;
                } else {
                    strcpy(previous_guesses[1], guess);
                }
                printf("\n");
                break;
            
            case 2:
                print_checked_word(word, previous_guesses[0]);
                print_checked_word(word, previous_guesses[1]);

                for (int i = 0; i < 2; i++)
                    printf("_ _ _ _\n");
                
                // citim o noua incercare
                printf("\nCuvântul este: ");
                if (scanf("%5s", guess) != 1) {
                    printf("Eroare la citirea cuvântului.\n");
                    return;
                }
                guess[4] = '\0';

                if (strcmp(guess, word) == 0) {
                    printf("Felicitări! Ai ghicit cuvântul %s!\n", word);
                    return;
                } else {
                    strcpy(previous_guesses[2], guess);
                }
                printf("\n");
                break;
            
            case 3:
                print_checked_word(word, previous_guesses[0]);
                print_checked_word(word, previous_guesses[1]);
                print_checked_word(word, previous_guesses[2]);
                printf("_ _ _ _\n");
                
                // citim o noua incercare
                printf("\nCuvântul este: ");
                if (scanf("%5s", guess) != 1) {
                    printf("Eroare la citirea cuvântului.\n");
                    return;
                }
                guess[4] = '\0';

                if (strcmp(guess, word) == 0) {
                    printf("Felicitări! Ai ghicit cuvântul %s!\n", word);
                    return;
                } else {
                    strcpy(previous_guesses[3], guess);
                }
                printf("\n");
                break;
            
            case 4:
                print_checked_word(word, previous_guesses[0]);
                print_checked_word(word, previous_guesses[1]);
                print_checked_word(word, previous_guesses[2]);
                print_checked_word(word, previous_guesses[3]);

                if (strcmp(guess, word) != 0) {
                    printf("\nAi pierdut! Cuvântul era %s.\n", word);
                }
                break;
        }
        guess_count++;
    }
}

void game_5_letters(char *word)
{
    printf("\n\n");
    printf("=======================\n\n");
}

void game_6_letters(char *word)
{
    printf("\n\n");
    printf("=======================\n\n");
}

void start_game(int word_length)
{
    char *word = malloc(word_length + 1);
    if (word == NULL) {
        perror("Error allocating memory for word");
        return;
    }

    // alegem un cuvant random
    get_word(word_length, word);

    // pornim jocul
    if (word_length == 4) {
        game_4_letters(word);
    } else if (word_length == 5) {
        game_5_letters(word);
    } else {
        game_6_letters(word);
    }

    free(word);
}

