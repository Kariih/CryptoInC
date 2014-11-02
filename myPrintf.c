#include <stdio.h>
#include "secretCoder.h"

void myPrintEncoded(char *inputTypes, char *souceFileName, char *keyFileName,
            char *encryptedMessage)
{
    int i = 0;
    int n = 0;


    printf("-----------------------ENCRYPTION--------------------------------");
    while(inputTypes[i] != '\0')
    {
        if(inputTypes[i] == 's')
        {
            printf("\nSourcefileName is: \n");
            n = 0;
            while(souceFileName[n] != '\0')
            {
                printf("%c",souceFileName[n]);
                n++;
            }
            printf("\n");
        }
        else if(inputTypes[i] == 'k')
        {
            printf("\nKeyfileName is: \n");
            n = 0;
            while(keyFileName[n] != '\0')
            {
                printf("%c",keyFileName[n]);
                n++;
            }
            printf("\n");
        }
        else if(inputTypes[i] == 'm')
        {
            printf("\nEncrypted message: \n");
            n = 0;
            while(encryptedMessage[n] != '\0')
            {
                printf("%c",encryptedMessage[n]);
                n++;
            }
            printf("\n");
        }
        else
        {
            printf("\ncould not print\n");
        }
        i++;

    }
    printf("-------------------------------------------------------");

}
void myPrintDecoded(char *inputTypes, char *keyFileName, char *decryptedMessage)
{
    int n = 0;
    int i = 0;
    printf("-------------------DECRYPTION------------------------------------");
    while(inputTypes[i] != '\0')
    {
        if(inputTypes[i] == 'k')
        {
            printf("\nKeyfileName is:\n ");
            n = 0;
            while(keyFileName[n] != '\0')
            {
                printf("%c",keyFileName[n]);
                n++;
            }
            printf("\n");
        }
        else if(inputTypes[i] == 'm')
        {
            printf("\nDecrypted message:\n ");
            n = 0;
            while(decryptedMessage[n] != '\0')
            {
                printf("%c",decryptedMessage[n]);
                n++;
            }
            printf("\n");
        }
        else
        {
            printf("\ncould not print\n");
        }
        i++;
    }
    printf("-------------------------------------------------------");
}
