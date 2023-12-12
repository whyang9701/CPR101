#define BUFFER_SIZE 80 
#include <stdio.h>
#include <string.h>
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


