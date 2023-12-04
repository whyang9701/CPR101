

#define _CRT_SECURE_NO_WARNINGS
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
    char input;
    do{
        printf("Select the function to test:\n");
        printf("1. fundamentals\n");
        printf("2. manipulating\n");
        printf("3. tokenizing\n");
        printf("4. converting\n");
        printf("q. quit\n");
        scanf("%c%*c", &input);
        if(input == '1'){
            printf("start testing fundamentals function\n");
            // calculate and display the lenght of a string
            fundamentals();
        }
        else if(input == '2'){
            printf("start testing manipulating function\n");
            // concatenate two strings
            manipulating();
        }
        else if(input == '3'){
            printf("start testing tokenizing function\n");
            // seperate the string by space
            tokenizing();
        }
        else if(input == '4'){
            printf("start testing converting function\n");
            // conver user input string to int
            converting();
        }
        else if(input == 'q'){
            printf("Goodbye!\n");
            return 0;       
        }
        else{
            printf("Invalid input\n");
        }

    }while(input != 'q');
}

//V2
void converting (void) {
    printf ("*** Start of Converting Strings to double Demo ***\n");
    char doubleString [BUFFER_SIZE];
    double doubleNumber;
    do{
        printf ("Type the double numeric string (q - to quit): \n");
        fgets (doubleString, BUFFER_SIZE, stdin) ;
        doubleString [strlen(doubleString) - 1] = '\0';
        if ((strcmp (doubleString, "q") != 0)) {
            doubleNumber = atof (doubleString);
            printf ("Converted number is %f\n", doubleNumber);
        }
     } while (strcmp(doubleString,"q") != 0);
    printf ("*** End of Converting Strings to double Demo ***\n\n");
}

// V2
void fundamentals (void) 
{

    printf ("*** Start of Measuring Strings Demo ***\n");
    char buffer2 [BUFFER_SIZE];

    do 
    {
        printf("Type a string (q - to quit):\n");

        //Get string input from the user
        fgets (buffer2, BUFFER_SIZE, stdin);

        //replace newline character with a null terminator
        buffer2[strlen(buffer2) - 1] = '\0';

        // print the lenght of the string, if the user didn't press 'q'
        if (strcmp(buffer2, "q") != 0)
        {
            printf("The length of \'%s\' is %d characters\n",
                buffer2, (int)strlen(buffer2));
        }

    }while (strcmp(buffer2,"q") != 0);

    printf ("*** End of Measuring Strings Demo ***\n\n");
}

void manipulating(void){
// V2
    printf ("*** start of Comparing Strings Demo ***\n");
    char compare1 [BUFFER_SIZE];
    char compare2 [BUFFER_SIZE];
    int result;
    do{
        printf ("Type the Ist string to compare (q - to quit) : \n");
        fgets (compare1, BUFFER_SIZE, stdin);
        compare1[strlen(compare1) - 1] = '\0';
        if (strcmp(compare1, "q") != 0) {
            printf("Type the 2nd string to compare: \n");
            fgets(compare2, BUFFER_SIZE, stdin);
            compare2[strlen(compare2) - 1] = '\0';
            result = strcmp (compare1, compare2);
            if (result < 0)
                printf("\'%s\' string is less than \'%s\'\n", compare1, compare2);
            else if (result == 0)
                printf("\'%s\' string is equal to \'%s\'\n", compare1, compare2);
            else 
                printf("\'%s\' string is greater than \'%s\'\n", compare1, compare2);
        }
    }while(strcmp(compare1, "q") != 0);
    printf("*** End of Comparing strings Demo ***\n\n");
}


void tokenizing(void) {
// V3 
    printf ("*** start of Tokenizing Sentences Demo ***\n");
    char sentences [BUFFER_SIZE];
    char* nextSentence = NULL;
    int sentencesCounter;
    do {
        printf ("Type a few sentences separated by dot (q - to quit): \n");
        fgets (sentences, BUFFER_SIZE, stdin);
        sentences [strlen(sentences) - 1] = '\0';
        if ((strcmp(sentences,"q") != 0)){
            nextSentence = strtok (sentences, ".");
            sentencesCounter = 1;
            while (nextSentence) {
                printf ("Senetnce #%d is \'%s\'\n", sentencesCounter++, nextSentence) ;
                nextSentence = strtok (NULL, ".");
            }
        }
    } while (strcmp(sentences, "q") != 0);
    printf ("*** End of Tokenizing Sentences Demo ***\n\n");
}


