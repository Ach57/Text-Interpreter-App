#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileread.h"
#define MAX_LENGTH = 1000;
#include <stdbool.h>


/*
    returns true if the word should be skipped and false if the word should not be skipped
*/
bool isWordSkip(char ** skipWordArray, char* word, int lengthOfSkippedWordArray){ 
    for(int i = 0; i< lengthOfSkippedWordArray; i++){
        if(strcmp(word, skipWordArray[i])==0){
            return true;
        }
    }
    return false; // word not to be skipped
   
}

/*
    returns the length of the resulted array and modifies the result by passing by reference
*/
int read_file(char*** result,char ** skipWordArray,char *input_file,int lengthOfSkippedWordArray , int n){ 
    // The number of skip words represents the lenght of the skip_word_array in this case;
    FILE *fp;
    fp = fopen(input_file, "r");
    if(fp == NULL){
        fprintf(stderr,"Error in opening the file\n");
        exit(1);
    }
    
    //n is the number of words in the file
    // Allocate memory for the array of strings
    char **array = (char **)malloc(n * sizeof(char *));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Read words from the file into the array
    int j=0;
    
    for(int i = 0; i<n; i++){
        char temp[100];
        if(fscanf(fp, "%99[^, \t\n\r\v\f.]", temp)!=1){ // Reading operation occurs here 
            fscanf(stderr, "Error reading words from the file \n");
            exit(1);
        }
        if(isWordSkip(skipWordArray,temp,lengthOfSkippedWordArray)==0){ // verify if the word should be skipped or not
            array[j] = strdup(temp);
            if(array[j] == NULL){
                fprintf(stderr, "Memory allocation failure for array[j]\n");
                exit(1);
            }
            j++;

        }

        fscanf(fp, "%*[, \t\n\r\v\f.]");
    }
    
    fclose(fp); //closing the file
    
    *result = array;

    /*
    for(int i = 0; i<j; i++){
        printf("array[%d]= %s\n", i, array[i]);
    }
     // Free the memory allocated for the array
    for(int i = 0; i<j;i++){
        free(array[i]);
    }
    free(array);*/

    return j;
}







/*
 * fileread.c:

        This file handles reading from the input file.
        It includes logic to skip specified words.
        Functions in this file will manage file I/O and processing the content of the file based on the skip words provided.*/
