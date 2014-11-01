#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "secretCoder.h"

int size = 10000;

int *openFile(char *filename)
{
    FILE *f = fopen(filename, "r");

    struct stat st;
    stat(filename, &st);
    size = st.st_size;
    char numberFromFile = '0';
    int count = 1;

    int *keyForEncryption = malloc(size*sizeof(int));
    while (fscanf(f, "%c", &numberFromFile) == 1)
    {
        keyForEncryption[count] = numberFromFile;
        count++;
    }
    fclose(f);
    return keyForEncryption;

}

char* filterAndGetKey(int *keyFile)
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
int findN(int currentCharToEncrypt, char *key, int n){
    while(currentCharToEncrypt != key[n])
    {
        n++;
    }
    return n;
}
char* findIndexAndAdd(int *messageToBeEncrypted, int size, char *key){
    const int MAX_BUFF = size*4;
    char *encryptedMessage = malloc(MAX_BUFF*sizeof(int));
    int length = 0;
    int d = 3;
    int lastUsed = 0;
    for (int i = 1; i <= size; i++)
    {
        int currentCharToEncrypt = messageToBeEncrypted[i];
        int n = 0;
        if ((currentCharToEncrypt>='a'&&currentCharToEncrypt<='z'))
        {
            if(i == 1)
            {
                n = findN(currentCharToEncrypt, key, n);
                lastUsed = n;
            }
            else
            {
                    n = findN(currentCharToEncrypt, key, n);
                    while(n<(lastUsed+d)&&n>(lastUsed-d))
                    {
                        n++;
                        n = findN(currentCharToEncrypt, key, n);
                    }
                    lastUsed = n;
            }
            length += snprintf(encryptedMessage + length, MAX_BUFF-length,
                                "%c%d%c", '[',n,']');
        }
        else if(currentCharToEncrypt>='A'&&currentCharToEncrypt<='Z')
        {
            currentCharToEncrypt = tolower(currentCharToEncrypt);
            if(i == 1)
            {
                n = findN(currentCharToEncrypt, key, n);
                lastUsed = -n;
            }
            else
            {
                    n = findN(currentCharToEncrypt, key, n);
                    while(n<(lastUsed+3)&&n>(lastUsed-3))
                    {
                        n++;
                        n = findN(currentCharToEncrypt, key, n);
                    }
                    lastUsed = -n;
            }
            length += snprintf(encryptedMessage + length, MAX_BUFF-length,
                                "%c%c%d%c", '[', '-',n,']');

        }
        else
        {
            length += snprintf(encryptedMessage + length, MAX_BUFF-length,
                               "%c", currentCharToEncrypt);
        }
    }
    printf("%s", encryptedMessage);
    return encryptedMessage;
}
char* encryptText(char *key, char *message){
    FILE *f = fopen(message, "r");
    struct stat st;
    stat(message, &st);
    int size = st.st_size;

    char numberFromFile = '0';
    int count = 1;
    int *messageToBeEncrypted = malloc(size*sizeof(int));

    while (fscanf(f, "%c", &numberFromFile) == 1)
    {
        messageToBeEncrypted[count] = numberFromFile;
        printf("%c",messageToBeEncrypted[count]);
        count++;
    }
    fclose(f);

    char *indexes = findIndexAndAdd(messageToBeEncrypted, size, key);
    return indexes;
}

char* encode(char *messageFile, char *keyFromFile){
    int *keyFile = openFile(keyFromFile);
    char *key = filterAndGetKey(keyFile);
    char *encrypted = encryptText(key, messageFile);
    return encrypted;
}
