#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

int *keyForEncryption;
int *messageToBeEncrypted;

int openFile()
{
    char *filename = "songLibrary/sweetChildGR.txt";
    FILE *f = fopen(filename, "r");

    struct stat st;
    stat(filename, &st);
    int size = st.st_size;
    char numberFromFile = '0';
    int count = 1;

    keyForEncryption = malloc(size*sizeof(int));
    while (fscanf(f, "%c", &numberFromFile) == 1)
    {
        keyForEncryption[count] = numberFromFile;
        count++;
    }
    fclose(f);
    return size;

}

int* filterAndGetKey(int size)
{
    int *lowercase = malloc(size*sizeof(int));
    int *removedAllButLetters = malloc(size*sizeof(int));
    int countLetters = 1;
    for(int i = 1; i <= size; i++)
    {
        int num = keyForEncryption[i];
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
void findIndexAndAdd(int *messageToBeEncrypted, int size, int *key){
    const int MAX_BUFF = 99999;
    char *encryptedMessage = malloc(MAX_BUFF);
    int length = 0;
    for (int i = 1; i <= size; i++)
    {
        int currentCharToEncrypt = messageToBeEncrypted[i];
        int n = 0;
        if ((currentCharToEncrypt>='a'&&currentCharToEncrypt<='z'))
        {
            while(currentCharToEncrypt != key[n])
            {
                n++;
            }
            length += snprintf(encryptedMessage + length, MAX_BUFF-length,
                                "%c%d%c", '[',n,']');
        }
        else if(currentCharToEncrypt>='A'&&currentCharToEncrypt<='Z')
        {
            currentCharToEncrypt = tolower(currentCharToEncrypt);
            while(currentCharToEncrypt != key[n])
            {
                n++;
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
    //return encryptedMessage;
}
void encryptText(int *key, char *message){
    FILE *f = fopen(message, "r");
    struct stat st;
    stat(message, &st);
    int size = st.st_size;

    char numberFromFile = '0';
    int count = 1;
    messageToBeEncrypted = malloc(size*sizeof(int));

    while (fscanf(f, "%c", &numberFromFile) == 1)
    {
        messageToBeEncrypted[count] = numberFromFile;
        printf("%c",messageToBeEncrypted[count]);
        count++;
    }
    fclose(f);

    findIndexAndAdd(messageToBeEncrypted, size, key);
}


int main()
{
    char *message = "inputMessage.txt";
    int size = openFile() + 1;
    int *key = filterAndGetKey(size);
    encryptText(key, message);

}
