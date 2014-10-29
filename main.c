#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

int *messageToBeEncrypted;
int *keyForEncryption;

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

void encryptText(int *key, char *message){
    FILE *f = fopen(message, "r");
    struct stat st;
    stat(message, &st);
    int size = st.st_size;

    char numberFromFile = '0';
    int count = 1;

    char *encryptedMessage[size];
    messageToBeEncrypted = malloc(size*sizeof(int));
    while (fscanf(f, "%c", &numberFromFile) == 1)
    {
        messageToBeEncrypted[count] = numberFromFile;
        count++;
    }
    fclose(f);

    for(int i = 0; i <= size; i++)
    {
        int countWhileLoop = 1;
        int firstChar = messageToBeEncrypted[i];
        if((firstChar>='a'&&firstChar<='z'))
        {
            while(firstChar != key[countWhileLoop])
            {
                countWhileLoop++;
            }
            encryptedMessage[i] += '['+ countWhileLoop +']';
        }
        else if(firstChar>='A'&&firstChar<='Z')
        {
            char lowerChar = tolower(firstChar);
            while(lowerChar != key[countWhileLoop])
            {
                countWhileLoop++;
            }
            encryptedMessage[i] += '[' + '-'+ countWhileLoop +']';
        }
        else
        {
            encryptedMessage[i] += firstChar;
        }
        for(int i = 1; i <= size+1; i++)
        {
            printf("%s", encryptedMessage[i]);
        }
    }
    //return encryptedMessage;
}

int main()
{
    char *message = "inputMessage.txt";
    int size = openFile() + 1;
    int *key = filterAndGetKey(size);
    encryptText(key, message);

}
