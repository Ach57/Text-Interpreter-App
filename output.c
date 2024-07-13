#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * sort_Input takes as parameter the sort_type as a pointer and checks if it is ASC or DESC, then sorts
    based on that.
*/
void sort_Input_And_Print_Result(char *sort_type, char ** ResultedArray, int lengthOfResultedArray){
    char * temp;
    int i; int j;
    if(strcmp(sort_type, "ASC") ==0){
        //Bubble sort for ASC
        for(i =0; i<lengthOfResultedArray-1; i++){
            for(j =0; j< lengthOfResultedArray-i-1; j++){
                if(strcmp(ResultedArray[j],ResultedArray[j+1])>0){
                    temp = ResultedArray[j];
                    ResultedArray[j] = ResultedArray[j+1];
                    ResultedArray[j+1]= temp;
                }

            }

        }

    }else{
        //Bubble sort for DESC
        for(i =0; i<lengthOfResultedArray-1; i++){
            for(j =0; j< lengthOfResultedArray-i-1; j++){
                if(strcmp(ResultedArray[j],ResultedArray[j+1])<0){
                    temp = ResultedArray[j];
                    ResultedArray[j] = ResultedArray[j+1];
                    ResultedArray[j+1]= temp;
                }

            }

        }

    }

    printf("Output: \n");
    
    for(i = 0; i< lengthOfResultedArray; i++){
        printf("%s ", ResultedArray[i]);
        if((i+1)%10 ==0){
            printf("\n");
        }
        
    }







}


/**
 * 
 *  * output.c:

    This file handles preparing and printing the final output.
    It also includes code for printing error messages.
    Functions here will be responsible for outputting results to the console or another specified output medium. 


*/






