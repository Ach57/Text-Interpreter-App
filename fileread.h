#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h> // Include for bool type
#include <stdio.h>   // Include for FILE operations
#include <stdlib.h>  // Include for exit()
#include <string.h>  // Include for strcmp

bool isWordSkip(char **skipWordArray, char *word, int lengthOfSkippedWordArray);
int read_file(char*** result,char **skipWordArray, char *input_file, int lengthOfSkippedWordArray, int n);

#endif // FUNCTIONS_H