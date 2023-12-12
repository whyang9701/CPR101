

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


int main(void)
{
    char input;
    do
    {
        // Menu
        printf("Select the function to test:\n");
        printf("1. fundamentals\n");
        printf("2. manipulating\n");
        printf("3. tokenizing\n");
        printf("4. converting\n");
        printf("q. quit\n");
        scanf("%c%*c", &input);
        if(input == '1')
        {
            printf("start testing fundamentals function\n");
            // Copying strings
            fundamentals();
        }
        else if(input == '2')
        {
            printf("start testing manipulating function\n");
            // Searching Strings
            manipulating();
        }
        else if(input == '3')
        {
            printf("start testing tokenizing function\n");
            // Tokenizing Sentences
            tokenizing();
        }
        else if(input == '4')
        {
            printf("start testing converting function\n");
            // Converting Strings to long
            converting();
        }
        else if(input == 'q')
        {
            printf("Goodbye!\n");
            return 0;
        }
        else
        {
            printf("Invalid input\n");
        }

    }while(input != 'q'); // Continues loop until "q" is pressed
}

void converting (void) 
{
//V3
    printf("*** Start of Converting Strings to long Demo ***\n");
    char longString [BUFFER_SIZE]; // declares the variables where to store the input
    long longNumber; // the string can hold upto 80 characters
    do
    {
        printf("Type the long numeric string (g - to quit):\n");
        fgets(longString, BUFFER_SIZE, stdin); // reads the input and stores it into longString. Read upto the maximum size which is 80 using standard input.
        longString[strlen(longString) - 1] = '\0'; // counts the string length and removes the newline character ('\n') from the end of the string.
        if ((strcmp (longString, "q") != 0))
        {
            longNumber = atol(longString); // The function atol converts the string longString to a long integer. It stores the long integer in longNumber.
            printf("Converted number is %ld\n", longNumber);
        }
    }while (strcmp(longString, "q") != 0) ; // Continues loop until "q" is pressed
    printf ("*** End of Converting Strings to long Demo ***\n\n");
}

void fundamentals (void) 
{
//V3
    printf ("*** start of Copying strings Demo ***\n");
    char destination [BUFFER_SIZE]; // declares the variables where to store the input
    char source [BUFFER_SIZE]; // the string can hold upto 79 meaningful characters
    do
    {
        destination [0] = '\0'; // resets the destination string to empty
        printf("Destination string is reset to empty\n"); 
        printf("Type the source string (q - to quit):\n");
        fgets(source, BUFFER_SIZE, stdin); // reads the input and stores it into source. Read upto the maximum size which is 80 using standard input.
        source[strlen(source) - 1] = '\0'; // guarantees that there is a null terminator at the end of the string.
        if (strcmp(source, "q") != 0)
        {
            strcpy(destination, source); // The function strcpy copies the string source to the string destination. It copies the null terminator as well.
            printf("New destination string is \'%s\'\n", destination); // Prints the new destination string
        }
    } while (strcmp (source, "q") != 0); // Continues loop until "q" is pressed
    printf ("*** End of Copying Strings Demo ***\n\n"); 
}

void manipulating(void)
{
//V3
    printf("*** Start of Searching Strings Demo ***\n");
    char haystack[BUFFER_SIZE]; // declares the variables where to store the input
    char needle[BUFFER_SIZE]; // the string can hold upto 80 characters
    char* occurrence = NULL; // pointer to the first occurrence of the substring
    do
    {
        printf("Type the string (q - to quit):\n");
        fgets(haystack, BUFFER_SIZE, stdin); // reads the input and stores it into haystack. Read upto the maximum size which is 80 using standard input.
        haystack[strlen(haystack) - 1] = '\0'; // counts the string length and removes the newline character ('\n') from the end of the string.
        if (strcmp(haystack, "q") != 0)
        {
            printf("Type the substring:\n");
            fgets(needle, BUFFER_SIZE, stdin); // reads the input and stores it into needle. Read upto the maximum size which is 80 using standard input.
            needle[strlen(needle) - 1] = '\0'; // counts the string length and removes the newline character ('\n') from the end of the string.
            occurrence = strstr(haystack, needle); // The function strstr finds the first occurrence of the substring needle in the string haystack. It stores the pointer to the first occurrence of the substring in occurrence.
            if (occurrence) // If the substring is found
            {
                printf("\'%s\' found at %d position\n", needle, (int)(occurrence - haystack)); // Prints the substring and the position where it was found
            }
            else
            {
                printf("Not found\n");
            }
        }
    } while (strcmp(haystack, "q") != 0); // Continues loop until "q" is pressed
    printf ("*** End of Searching Strings Demo ***\n\n");
}


void tokenizing(void)
{
//V3
    printf ("*** Start of Tokenizing Sentences Demo ***\n");
    char sentences[BUFFER_SIZE]; // declares the variables where to store the input
    char* nextSentence = NULL; // pointer to the next sentence
    int sentencesCounter; // counter for the number of sentences
    do
    {
        printf("Type a few sentences separated by dot (q - to quit):\n");
        fgets(sentences, BUFFER_SIZE, stdin); // reads the input and stores it into sentences. Read upto the maximum size which is 80 using standard input.
        sentences[strlen(sentences) - 1] = '\0'; // counts the string length and removes the newline character ('\n') from the end of the string.
        if ((strcmp(sentences, "q") != 0))
        {
            nextSentence = strtok (sentences,"."); // The function strtok is used to tokenize the string sentences. It returns a pointer to the first token found in the string.
            // The first parameter is the string to be tokenized and the second parameter is the delimiter. In this case, the delimiter is the dot.
            sentencesCounter = 1; // The counter is initialized to 1 because the first sentence is tokenized.
            while (nextSentence) // The while loop continues until the nextSentence pointer is NULL. This means that there are no more tokens to be found in the string.
            {
                printf ("Senetnce #%d is \'%s\'\n", sentencesCounter++, nextSentence);
                nextSentence = strtok(NULL, "."); // The function strtok is called again to find the next token in the string.
                // The first parameter is NULL because the function remembers the string that was passed to it in the first call.
            }
        }
    } while (strcmp(sentences, "q") != 0); // Continues loop until "q" is pressed
    printf ("*** End of Tokenizing Sentences Demo ***\n\n");
}
