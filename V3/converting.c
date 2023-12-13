#include "converting.h"
void converting (void) 
{
//V3
    printf("*** Start of Converting Strings to long Demo ***\n");
    char longString [BUFFER_SIZE]; // declares the variables where to store the input
    long longNumber; // the string can hold upto 80 characters
    do
    {
        printf("Type the long numeric string (q - to quit):\n");
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

