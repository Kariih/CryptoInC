#include <stdio.h>
#include "secretCoder.h"

int main()
{
    //encode
    char *keyFile = "songLibrary/sweetChildGR.txt";
    char *messageFile = "inputMessage.txt";
    char *encrypted = encode(messageFile, keyFile);

    //decode
    char *keyFromFile2 = "songLibrary/sweetChildGR.txt";
    char *keyFile2 = openFile(keyFromFile2);
    char *key2 = filterAndGetKey(keyFile2);
    decodeMessage(key2, encrypted);
}
