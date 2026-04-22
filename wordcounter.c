#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LINE_LENGTH 1024

int main()
{
    FILE *filePointer = fopen("repeated.txt", "r");
    
    if (filePointer == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    char buffer[LINE_LENGTH];
    int lines = 0, words = 0;
    char lastChar = ' ';

    while (fgets(buffer, sizeof(buffer), filePointer) != NULL)
    {
        lines++; 

        for (size_t i = 0; buffer[i] != '\0'; i++)
        {
            const char current = buffer[i];

            // if word ended
            if (isspace(current) && !isspace(lastChar)) 
            // basically if this char is a space and the last one isnt
            // YEAH ik there might be a bug if theres 2 spaces or smth
            {
                words++;
            }
            
            lastChar = current;
        }
    }

    // in case the file doesnt end with a newline
    if (!isspace(lastChar) && lastChar != '\0') {
        words++;
    }

    fclose(filePointer);

    // Final Output
    printf("Total Lines: %d\n", lines);
    printf("Total Words: %d\n", words);

    return 0;
}