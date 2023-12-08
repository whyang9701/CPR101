

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
void converting (void)
{
    // Start of Converting Strings to double Demo
    printf ("*** Start of Converting Strings to double Demo ***\n");
    char doubleString[BUFFER_SIZE];
    double doubleNumber; // Variable for the converted number

    do
    {
        // Prompt the user to enter a double numeric string
        printf("Type the double numeric string (q - to quit):\n");
        fgets(doubleString, BUFFER_SIZE, stdin); // Read the string from the user
        doubleString[strlen(doubleString) - 1] = '\0'; // Replace the newline char with a null terminator

        // If the user didn't press 'q', convert the string to a double number
        if ((strcmp (doubleString, "q") != 0))
        {
            // Convert the string to a double number using atof
            doubleNumber = atof(doubleString);
            printf ("Converted number is %f\n", doubleNumber);
        }
     } while (strcmp(doubleString, "q") != 0); // If the user pressed 'q', exit the loop

    printf ("*** End of Converting Strings to double Demo ***\n\n");
}

// V2
void fundamentals (void) 
{
    printf("*** Start of Measuring Strings Demo ***\n");
    char buffer2[BUFFER_SIZE];

    do 
    {
        printf("Type a string (q - to quit):\n");

        //Get string input from the user
        fgets(buffer2, BUFFER_SIZE, stdin);

        //replace newline character with a null terminator
        buffer2[strlen(buffer2) - 1] = '\0';

        // print the lenght of the string, if the user didn't press 'q'
        if (strcmp(buffer2, "q") != 0)
        {
            printf("The length of \'%s\' is %d characters\n",
                buffer2, (int)strlen(buffer2));
        }

    }while (strcmp(buffer2, "q") != 0);

    printf("*** End of Measuring Strings Demo ***\n\n");
}

void manipulating(void)
{
    // V2
    // Print start message
    printf("*** start of Comparing Strings Demo ***\n");

    // Declare two character arrays to store strings for comparison
    char compare1[BUFFER_SIZE];
    char compare2[BUFFER_SIZE];
    // store the compared results in a variable named result
    int result;

    // Loop to continue comparing strings until the user enters 'q'
    do
    {
        printf("Type the Ist string to compare (q - to quit) : \n");

        // Read the input string from the user
        fgets(compare1, BUFFER_SIZE, stdin);

        // Remove the newline character from the input string
        compare1[strlen(compare1) - 1] = '\0';

        // Check if the entered string is not 'q'
        if (strcmp(compare1, "q") != 0)
        {
            printf("Type the 2nd string to compare: \n");

            // Read the second input string from the user
            fgets(compare2, BUFFER_SIZE, stdin);

            // Remove the newline character from the second input string
            compare2[strlen(compare2) - 1] = '\0';
            // Compare the two strings and store the result
            result = strcmp(compare1, compare2);
            // Output the result of the string comparison
            if (result < 0)
            {
                printf("\'%s\' string is less than \'%s\'\n", compare1, compare2);
            }   
            else if (result == 0)
            {
                printf("\'%s\' string is equal to \'%s\'\n", compare1, compare2);
            }
            else
            {
                printf("\'%s\' string is greater than \'%s\'\n", compare1, compare2);
            }
        }
    } while (strcmp(compare1, "q") != 0); // Continue the loop until the user enters 'q'
    printf("*** End of Comparing strings Demo ***\n\n");
}


void tokenizing(void)
{
// V2
    // Start of Tokenizing Phrases Demo
    printf("*** Start of Tokenizing Phrases Demo ***\n");
    char phrases[BUFFER_SIZE];
    char* nextPhrase = NULL; // Pointer to the next phrase
    int phrasesCounter; // Counter for the number of phrases
    do
    {
        // Prompt the user to enter a few phrases separated by comma
        printf("Type a few phrases separated by comma(q - to quit):\n");
        fgets(phrases, BUFFER_SIZE, stdin); // Read the string from the user
        phrases[strlen(phrases) - 1] = '\0'; // Replace the newline char with a null terminator

        // If the user didn't press 'q', tokenize the string
        if ((strcmp(phrases, "q") != 0))
        {
            // Tokenize the string using strtok
            nextPhrase = strtok(phrases, ",");
            phrasesCounter = 1; // Initialize the phrases counter
            // Loop to print the phrases
            while (nextPhrase)
            {
                // Print the phrase with the phrase number
                printf("Phrases #%d is \'%s\'\n", phrasesCounter++, nextPhrase);
                // Tokenize the next phrase
                nextPhrase = strtok (NULL, ",");
            }
        }
    } while (strcmp(phrases, "q") != 0); // If the user pressed 'q', exit the loop
    printf ("*** End of Tokenizing Phrases Demo ***\n\n");
}


