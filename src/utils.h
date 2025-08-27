#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

char *get_random_word(FILE *file, int word_length, char *buffer);
void print_checked_word(const char *word, const char *guess);