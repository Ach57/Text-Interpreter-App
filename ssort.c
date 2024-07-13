#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fileread.h"
#include "wordtype.h"
#include "output.h"

int handle_Array_Size(char *n_str){ // takes as argument the pointer to the string of argv[2]
    // Check if <n> is a valid integer
    for(int i = 0; n_str[i]!='\0' ; i++){ // loop until the the end of the array
        if(!isdigit(n_str[i])){ // check if its a digit or not
            fprintf(stderr, "Invalid value for <n> found %s\n", n_str);
            exit(1);
        }
    }

    // if program not terminated, then n is a number
    int n = atoi(n_str); // Ascii to integer The array size is specified by <n>.
    if(n<=0){
        fprintf(stderr, "Invalid value for <n> found: %d\n", n);
        exit(1);
    }

    return n;

}

char* handle_w_type(char *w_type){ // takes argv[3] as input
    if(strcmp(w_type, "ALPHA") == 0){
        return "ALPHA";
    }else if(strcmp(w_type, "ALPHANUM")==0){
        return "ALPHANUM";
    } else if(strcmp(w_type, "ALL")==0){
        return "ALL";
    } else{
        
        return "INVALID";
    }


}

void veirfy_w_type(char *w_type){
    if(strcmp(w_type,"INVALID") == 0){
        fprintf(stderr,"The entered type was not found within range {ALPHA, ALPHANUM, ALL}: %s\n", w_type);
        exit(1);
    }
}

int main(int argc, char *argv[]){
    // handling the number of arguments entered by the user:
    if(argc<4){
        fprintf(stderr, "Usage: %s <inputfile> <n> <wtype> <sorttype> [<skipword1> <skipword2> ...]\n", argv[0]); //standard error message
        exit(1);
    }

    char *input_file = argv[1]; // input file requires handling
    int n = handle_Array_Size((char *) argv[2]); // handles the int entered 
    char *w_type = handle_w_type((char*) argv[3]);  // ALPHA, ALPHANUM, ALL
    veirfy_w_type(w_type); // verifies if w_type is INVALID
    char *sort_type = "ASC"; //default value ASC
    int skip_count =4; // Skipword count starting at 4
    if(argc>4 && (strcmp(argv[4], "ASC")==0||strcmp(argv[4], "DESC") ==0)){
        sort_type= argv[4];
        skip_count =5; // starting skipword at 5
    }

    char ** skipWordArray = argv+skip_count; // puts all the skipped words in an array 
    int lengthOfSkippedArray = argc-skip_count; // length of the skipped word array 

    char ** word_storage = NULL; // Word_storage will contain all the words 
    // The function read_file should give back the lenght of the word_storage and by reference nodify word_storage
    int storageLenght = read_file(&word_storage, skipWordArray,input_file,lengthOfSkippedArray,n); 

    if(strcmp(w_type, "ALPHA") == 0){ // Checks if the wordtype = "ALPHA"
        storageLenght = is_ALPHA(&word_storage, word_storage, storageLenght); // calls is_ALPHA FUNCTION
    }else if(strcmp(w_type, "ALPHANUM")==0){
        storageLenght = is_ALPHANUM(&word_storage, word_storage, storageLenght); // Calls is_ALPHANUM FUNCTION
    }

    sort_Input_And_Print_Result(sort_type,word_storage,storageLenght);
    
    // Free memory allocation
    for(int i = 0; i<storageLenght; i++){
        free(word_storage[i]);

    }
    free(word_storage);


    
    return 0;


}



/**
 * ssort.c:

        This file contains the main() function.
        It processes command line arguments.
        It serves as the entry point of the program and coordinates the overall flow.

 * fileread.c:

        This file handles reading from the input file.
        It includes logic to skip specified words.
        Functions in this file will manage file I/O and processing the content of the file based on the skip words provided.
 
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

 * output.c:

    This file handles preparing and printing the final output.
    It also includes code for printing error messages.
    Functions here will be responsible for outputting results to the console or another specified output medium. 



*/