#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordtype.h"
#include <ctype.h>

/*
    is_ALPHA takes as input array of strings and the length of the array and the expected result passed by reference
    returns the length of the new array 
*/
int is_ALPHA(char *** expectedResult,char ** resulted_Array, int lengthOfArray){
    char ** result = malloc(lengthOfArray* sizeof(char*));

    if(result == NULL){ // Error Checking for memory allocation
        fprintf(stderr, "Failure to memory allocate in ALPHA {result}\n");
        exit(1);
    }
    int j =0;

    for(int i = 0; i< lengthOfArray; i++){
        int p =0;
        for (p = 0; resulted_Array[i][p] != '\0' && isalpha(resulted_Array[i][p]); p++) {
            // Loop through each character of the string to check if it's alphabetic
        }
        if (resulted_Array[i][p] == '\0') {
            result[j++] = resulted_Array[i];
        }
    }
    *expectedResult = result; // pass by reference
    return j; // returns the length of the new ALPHA array
}

/*
    is_ALPHANUM takes as input array of strings and the length of the array and the expected result passed by reference
    returns the length of the new array 
*/

int is_ALPHANUM(char *** expectedResult,char ** resulted_Array, int lengthOfArray){
    char ** result = malloc(lengthOfArray * sizeof(char*));
    if(result ==NULL){
        fprintf(stderr,"Failure to memory allocate in ALPHANUM\n");
        exit(1);
    }
    int j = 0;
    for(int i = 0; i< lengthOfArray; i++){
        int p = 0;

        for(p = 0; resulted_Array[i][p]!='\0' && (isalpha(resulted_Array[i][p]) || isdigit(resulted_Array[i][p]) ); p++ ) {

        }
        if(resulted_Array[i][p]=='\0'){
            result[j++] = resulted_Array[i];
        }
    }

    *expectedResult = result;

    return j;


}


/*
* wordtype.c:

    This file contains logic related to word types (e.g., ALPHA, ALPHANUM, ALL).
    Functions in this file will categorize or filter words based on their types.
    It may include validation for word types and processing words accordingly.
    <wtype> specifies the word type. They are as follows:
        a.
        ALPHA: only English words composed of [a-z] and [A-Z].
        b.
        ALPHANUM: all words composed by alphanumeric characters.
        c.
        ALL: all words separated by whitespaces: blank, tab, null, vertical tab, … as well as the comma character as separator.
        Examples of words are: $, apple_1, …
        Note that <wtype> is also a required parameter, and in case it is missing, program must display a proper error message; and terminate abnormally (error code 2).
    Also note that there is no null/empty word. For example a line containing “a,,apple,,,test” (with options WORD, ALPHNUMERIC, or ALL) contains three word only: a, apple, and test.
*/



