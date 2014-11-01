#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "secretCoder.h"


void decodeMessage(char *key, char *message)
{
    int size = 0;
    while(message[size] != '\0'){
        size++;
    }
    char findNumbers[10];
    char *decryptedMessage = malloc(size*sizeof(int));
    int letter = 0, countNumber = 0, index = 0, upper = 0;
    char letterInKey;

   for (int i = 0; i <= size; i++)
    {

        if(message[i]>='0'&&message[i]<='9')
        {
            findNumbers[countNumber] = message[i];
            countNumber++;
        }
        else if(message[i] == ']')
        {
            letter = atoi(findNumbers);
            letterInKey = key[letter];

           if(upper == 1){
                letterInKey = toupper(letterInKey);
                upper = 0;
            }
            decryptedMessage[index] = letterInKey;
            index++;
            countNumber = 0;
            memset(findNumbers, 0, 10);
        }
        else if(message[i] == '-')
        {
            upper = 1;
        }
        else if(message[i] != '[')
        {
            decryptedMessage[index] = message[i];
            index++;
        }
    }


    printf("\n");
    for(int i = 0; i <= index; i++)
    {
        printf("%c",decryptedMessage[i]);
    }

    //return decryptedMessage;
}
