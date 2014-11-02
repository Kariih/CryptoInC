#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "secretCoder.h"
int size = 0;


//find index in key
int findN(int currentCharToEncrypt, char *key, int n){
    while(currentCharToEncrypt != key[n])
    {
        n++;
        if(key[n] == '\0')
        {
            printf("unable to encrypt with key");
            exit(0);
        }
    }
    return n;
}
//Find which type of char it is, and fulfill the d condition.
char* findIndexAndAdd(char *messageToBeEncrypted, int size, char *key, int distance){
    const int MAX_BUFF = size*4;
    char *encryptedMessage = malloc(MAX_BUFF*sizeof(int));
    int length = 0;
    int d = 3;
    int lastUsed = distance;
    for (int i = 1; i <= size; i++)
    {
        int currentCharToEncrypt = messageToBeEncrypted[i];
        int n = 0;

        //if there is a lowercase char
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
                    int rounds = 0;
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
        //if there is a uppercase char
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
                    int timesForFindingNewIdex;
                    while(n<(lastUsed+3)&&n>(lastUsed-3))
                    {
                        n++;
                        n = findN(currentCharToEncrypt, key, n);
                        timesForFindingNewIdex++;
                        if(timesForFindingNewIdex == 2)
                        {
                            printf("unable to fulfill d condition");
                        }
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
    return encryptedMessage;
}
//navigate to other encrypt methodes.
char* encryptText(char *key, char *message, int distance){

    char *messageToBeEncrypted = openFile(message);
    char *indexes = findIndexAndAdd(messageToBeEncrypted, size, key, distance);
    return indexes;
}
//main encode method
char* encode(char *messageFile, char *keyFromFile, int distance){
    char *keyFile = openFile(keyFromFile);
    char *key = filterAndGetKey(keyFile);
    char *encrypted = encryptText(key, messageFile, distance);
    return encrypted;
}
