#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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

