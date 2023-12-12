#define BUFFER_SIZE 80 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
