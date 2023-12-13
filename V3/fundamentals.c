#include "fundamentals.h"
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

