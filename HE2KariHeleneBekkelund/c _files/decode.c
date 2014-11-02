#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "secretCoder.h"


char* decode(char *key, char *message)
{

    //Check for lenght of message file.
    while(message[size] != '\0'){
        size++;
    }
    char findNumbers[10];
    char *decryptedMessage = malloc(size*sizeof(int));
    int letter = 0, countNumber = 0, index = 0, upper = 0;
    char letterInKey;


    //start decryption
   for (int i = 0; i <= size; i++)
    {

        //filter out indexes
        if(message[i]>='0'&&message[i]<='9')
        {
            findNumbers[countNumber] = message[i];
            countNumber++;
        }
        else if(message[i] == ']')
        {
            //add indexes and convert to char
            letter = atoi(findNumbers);
            letterInKey = key[letter];

            //add uppercase letters
           if(upper == 1){
                letterInKey = toupper(letterInKey);
                upper = 0;
            }
            //add into final pointer
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
            //add to pointer chars
            decryptedMessage[index] = message[i];
            index++;
        }
    }

    //print the decoded message
    printf("\nDecoded message: \n");
    for(int i = 0; i <= index; i++)
    {
        printf("%c",decryptedMessage[i]);
    }

    return decryptedMessage;
}
