#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "secretCoder.h"

char* filterAndGetKey(char *keyFile)
{
    int *lowercase = malloc(size*sizeof(int));
    char *removedAllButLetters = malloc(size*sizeof(int));
    int countLetters = 1;
    for(int i = 1; i <= size; i++)
    {
        int num = keyFile[i];
        lowercase[i] = tolower(num);
    }
    for(int i = 1; i<= size; i++)
    {
        if((lowercase[i]>='a'&&lowercase[i]<='z'))
        {
            removedAllButLetters[countLetters] = lowercase[i];
            printf("%c", removedAllButLetters[countLetters]);
            countLetters++;
        }
    }
    return removedAllButLetters;
}
