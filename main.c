#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

char *messageToBeEncrypted;
int *keyForEncryption;

int openFile()
{
    char *filename = "songLibrary/sweetChildGR.txt";
    FILE *f = fopen(filename, "r");

    struct stat st;
    stat(filename, &st);
    int size = st.st_size;
    char numberFromFile = '0';
    int count = 0;
    int ch = getc(f);

    keyForEncryption = malloc(size*sizeof(int));
    while (fscanf(f, "%c", &numberFromFile) == 1)
    {
        keyForEncryption[count] = numberFromFile;
        count++;
    }
    fclose(f);
    return size;

}

char* filterAndGetKey(int size)
{
    int *lowercase = malloc(size*sizeof(int));
    int *removedAllButLetters = malloc(size*sizeof(int));
    int countLetters = 0;
    for(int i = 0; i <= size; i++)
    {
        int num = keyForEncryption[i];
        lowercase[i] = tolower(num);
    }
    for(int i = 0; i<= size; i++)
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

void encrypt(){
    printf("%s", "this will be encrypted");
}

int main()
{
    int size = openFile();
    char *key = filterAndGetKey(size);
    getMessage();
    encrypt(key, message);

}
