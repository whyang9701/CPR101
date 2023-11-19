#define BUFFER_SIZE 80 
#define NUM_INPUT_SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizing.h"
#include "manipulating.h"
#include "fundamentals.h"
#include "converting.h"


int main(void){
    printf("start testing fundamentals function\n");
    // print the character at the position
    fundamentals();

    printf("start testing manipulating function\n");
    // concatenate two strings
    manipulating();

    printf("start testing tokenizing function\n");
    // seperate the string by space
    tokenizing();


    printf("start testing converting function\n");
    // conver user input string to int
    converting();
    return 0;
}

//V1
void converting (void) {
    printf ("*** Start of Converting Strings to int Demo ***\n");
    char intstring [BUFFER_SIZE];
    int intNumber;
    do {
        printf ("Type an int numeric string (q - to quit) : \n"); 
        fgets (intstring, BUFFER_SIZE, stdin);
        intstring [strlen (intstring) - 1] = '\0';
        if (strcmp (intstring, "q" ) != 0) {
            intNumber = atoi (intstring) ;
            printf ("Converted number is %d\n", intNumber) ;
        }
    }while (strcmp (intstring, "q") != 0);
    printf ("*** End of Converting Strings to int Demo ***\n\n");
}

void fundamentals (void) {
// V1
    printf ("*** Start of Indexing Strings Demo ***\n");
    char buffer1 [BUFFER_SIZE];
    char numInput [NUM_INPUT_SIZE];
    size_t position;
    do {
        printf ("Type not empty string (q - to quit): \n");

        //read input from the user
        fgets (buffer1, BUFFER_SIZE, stdin) ;

        // ensures that the input has a null terminator
        buffer1 [strlen (buffer1) - 1] = '\0';

        //check if user has not pressed "q"
        if (strcmp (buffer1, "q") != 0) {            
            printf ("Type the character position within the string: \n"); 

            //read numeric imput
            fgets (numInput, NUM_INPUT_SIZE, stdin);
            // ensure that the input has a null terminator
            numInput [strlen (numInput) - 1] = '\0';
            //convert input to an integer
            position = atoi (numInput) ;
            //check if user input was bigger than the string
            //and if it is set the input to the max position available
            if (position >= strlen (buffer1)) {
                position = strlen (buffer1) - 1;
                printf("Too big... Position reduced to max. availbale\n");
            }
            // shows what character is available at the inputed position
            printf ("The character found at %d position is \'%c\'\n",
                        (int) position, buffer1 [position]);
        }
    //repeats the loop if user has not pressed "q"
    } while (strcmp (buffer1,"q") != 0);
    printf ("*** End of Indexing Strings Demo ***\n\n");
}

// V1
void manipulating (void) {
    printf("*** Start of Concatenating Strings Demo ***\n");
    char string1 [BUFFER_SIZE * 2];
    char string2 [BUFFER_SIZE];
    do {
        printf ("Type the 1st string (q - to quit): \n"); 
        fgets (string1, BUFFER_SIZE, stdin) ; 
        string1 [strlen(string1) - 1] = '\0';
        if ((strcmp (string1, "q") != 0)) {
            printf ("Type the 2nd string: \n");
            fgets (string2, BUFFER_SIZE, stdin);
            string2 [strlen(string2) - 1] = '\0';
            strcat (string1, string2);
            printf ("Concatenated string is \'%s\'\n", string1) ;
        }
    } while (strcmp (string1, "q") != 0);
    printf ("*** End of Concatenating Strings Demo ***\n\n") ;
}

// V1
void tokenizing (void) {
printf ("*** Start of Tokenizing Words Demo ***\n");
    char words [BUFFER_SIZE];
    char* nextWord = NULL;
    int wordsCounter;
    do {
        printf ("Type a few words separated by space (q - to quit): \n"); 
        fgets (words, BUFFER_SIZE, stdin) ;
        words [strlen (words) - 1] = '\0';
        if (strcmp (words, "q") != 0) {
            nextWord = strtok (words, " ");
            wordsCounter = 1;
            while (nextWord) {
                printf ("Word #%d is \'%s\'\n", wordsCounter++, nextWord) ;
                nextWord = strtok (NULL, " ");
            }
        }
    } while (strcmp (words, "q") != 0) ;
    printf ("*** End of Tokenizing Words Demo ***\n\n");
}

