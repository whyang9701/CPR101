

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

void converting (void)
{
// v3
    printf ("*** Start of Converting Strings to long Demo ***\n");
    char longString [BUFFER_SIZE];
    long longNumber;
    do {
        printf ("Type the long numeric string (g - to quit):\n");
        fgets (longString, BUFFER_SIZE, stdin);
        longString [strlen (longString) - 1] = '\0';
        if ((strcmp (longString, "q") != 0)) {
        longNumber = atol(longString);
        printf ("Converted number is %ld\n", longNumber) ;
        }
    }while (strcmp (longString, "q") != 0) ;
    printf ("*** End of Converting Strings to long Demo ***\n\n");
}

void fundamentals (void) 
{
   // v3
printf ("*** start of Copying strings Demo ***\n");
    char destination [BUFFER_SIZE];
    char source [BUFFER_SIZE];
    do
    {
        destination [0] = '\0';
        printf("Destination string is reset to empty\n");
        printf("Type the source string (q - to quit):\n");
        fgets(source, BUFFER_SIZE, stdin);
        source[strlen(source) - 1] = '\0';
        if (strcmp (source, "q") != 0){
            strcpy(destination, source);
            printf("New destination string is \'%s\'\n", destination);
        }
    } while (strcmp (source, "q") != 0) ;
    printf ("*** End of Copying Strings Demo ***\n\n"); 
}

void manipulating(void)
{
//V3
    printf("*** Start of Searching Strings Demo ***\n");
    char haystack [BUFFER_SIZE];
    char needle [BUFFER_SIZE];
    char* occurrence = NULL;
    do {
        printf ("Type the string (q - to quit):\n");
        fgets (haystack, BUFFER_SIZE, stdin);
        haystack [strlen (haystack) - 1] = '\0';
        if (strcmp (haystack, "q") != 0) {
            printf("Type the substring:\n"); 
            fgets(needle, BUFFER_SIZE, stdin);
            needle[strlen (needle) - 1] = '\0';
            occurrence = strstr(haystack, needle);
            if (occurrence)
                printf ("\'%s\' found at %d position\n", needle, (int)(occurrence - haystack));
            else 
                printf ("Not found\n");
        }
    } while (strcmp (haystack, "q") != 0);
    printf ("*** End of Searching Strings Demo ***\n\n");
}


void tokenizing(void)
{
//V3
    printf ("*** start of Tokenizing Sentences Demo ***\n");
    char sentences[BUFFER_SIZE];
    char* nextSentence = NULL;
    int sentencesCounter;
    do{
        printf ("Type a few sentences separated by dot (q - to quit):\n");
        fgets (sentences, BUFFER_SIZE, stdin);
        sentences [strlen (sentences) - 1] = '\0';
        if ((strcmp(sentences, "q") != 0)){
            nextSentence = strtok (sentences,".");
            sentencesCounter = 1;
            while (nextSentence) {
                printf ("Senetnce #%d is \'%s\'\n", sentencesCounter++, nextSentence);
                nextSentence = strtok (NULL, ".");
            }
        }
    } while (strcmp (sentences, "q") != 0);
    printf ("*** End of Tokenizing Sentences Demo ***\n\n");
}
