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
            // print the character at the position
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

//V1
void converting (void) {

    // Print a heading indicating the start of the demo
    printf ("*** Start of Converting Strings to int Demo ***\n");

    // Declare a character array to store the user input
    char intstring [BUFFER_SIZE];

    // Declare an integer variable to store the converted number
    int intNumber;

    // Loop until the user enters 'q'
    do {
        
        // Print a prompt asking the user to enter a numeric string
        printf ("Type an int numeric string (q - to quit) : \n");
        
        // Read a line of input from the user 
        fgets (intstring, BUFFER_SIZE, stdin);
        
        // Remove the newline character from the end of the input string
        intstring [strlen (intstring) - 1] = '\0';
        
        // Check if the input string is not 'q'
        if (strcmp (intstring, "q" ) != 0) {
            
            // Convert the input string to an integer using atoi()
            intNumber = atoi (intstring) ;
            
            // Print the converted number
            printf ("Converted number is %d\n", intNumber) ;
        }
    }while (strcmp (intstring, "q") != 0);
    
    // Print a heading indicating the end of the demo
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
                printf("Too big... Position reduced to max. available\n");
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
// Start of version 1 of the manipulating function
void manipulating(void)
{
    // Print a message to indicate the start of the concatenating strings demo
    printf("*** Start of Concatenating Strings Demo ***\n");
    // Declare a string array that can hold twice the BUFFER_SIZE to store the concatenated string
    char string1[BUFFER_SIZE * 2];
    // Declare a second string array of BUFFER_SIZE for the second input string
    char string2[BUFFER_SIZE];

    // A do-while loop to keep the program running until 'q' is entered
    do
    {
        // Prompt the user to type the first string with 'q' as the quit command
        printf("Type the 1st string (q - to quit):\n");
        // Read the input from the user into string1 up to BUFFER_SIZE characters
        fgets(string1, BUFFER_SIZE, stdin);
        // Replace the newline character at the end of the input with a null terminator
        string1[strlen(string1) - 1] = '\0';
        // Check if the input string is not 'q' to continue

        if ((strcmp(string1, "q") != 0))
        {
            // Prompt the user to type the second string
            printf("Type the 2nd string:\n");
            // Read the second string input into string2
            fgets(string2, BUFFER_SIZE, stdin);
            // Replace the newline character at the end of string2 with a null terminator
            string2[strlen(string2) - 1] = '\0';
            // Concatenate string2 to the end of string1
            strcat(string1, string2);
            // Print the concatenated string
            printf("Concatenated string is \\%s\\\n", string1);
        }

        // Continue the loop until 'q' is entered as the first string
    } while (strcmp(string1, "q") != 0);

    // Print a message to indicate the end of the concatenating strings demo
    printf("*** End of Concatenating Strings Demo ***\n\n");
}



// V1
// Function to demonstrate tokenizing words
void tokenizing(void) {
    printf("*** Start of Tokenizing Words Demo ***\n");

    // Declare a character array to store words
    char words[BUFFER_SIZE];
    // Pointer to the next word in the input
    char* nextWord = NULL;
    // Counter to keep track of the number of words
    int wordsCounter;

    // Loop until the user enters "q"
    do {
        // Prompt the user to input a few words separated by space
        printf("Type a few words separated by space (q - to quit): \n");
        // Read the input string from the user
        fgets(words, BUFFER_SIZE, stdin);
        // Remove the newline character at the end of the input
        words[strlen(words) - 1] = '\0';

        // Check if the input is not "q"
        if (strcmp(words, "q") != 0) {
            // Tokenize the input string using space as the delimiter
            nextWord = strtok(words, " ");
            // Reset the word counter
            wordsCounter = 1;

            // Loop through each tokenized word
            while (nextWord) {
                // Print the current word and its number
                printf("Word #%d is '%s'\n", wordsCounter++, nextWord);
                // Get the next tokenized word
                nextWord = strtok(NULL, " ");
            }
        }
    } while (strcmp(words, "q") != 0);

    // Print the end message of the demo
    printf("*** End of Tokenizing Words Demo ***\n\n");
}


