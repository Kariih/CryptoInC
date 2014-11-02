#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "secretCoder.h"

//Opens key and message files.
char *openFile(char *filename)
{
    FILE *f;
    if(access(filename, F_OK) != -1) {
        printf("\nfound file\n");
        f = fopen(filename, "r");
    } else {
        printf("\ncould not find file with name: %s\n", filename);
        exit(0);
    }

    struct stat st;
    stat(filename, &st);
    size = st.st_size;
    char numberFromFile = '0';
    int count = 1;

    int *dataFromFile = malloc(size*sizeof(int));
    while (fscanf(f, "%c", &numberFromFile) == 1)
    {
        dataFromFile[count] = numberFromFile;
        count++;
    }
    fclose(f);
    char *returnPointer = malloc(size*sizeof(int));
    for (int i = 0; i <= size; i++)
    {
        returnPointer[i] = dataFromFile[i];
    }
    return returnPointer;

}
