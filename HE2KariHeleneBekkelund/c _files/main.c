#include <stdio.h>
#include "secretCoder.h"

int main()
{
    //encode
    int distance = 3;
    char *keyFile = "songLibrary/sweetChildGR.txt";
    char *messageFile = "inputMessage.txt";
    char *encrypted = encode(messageFile, keyFile, distance);

    //decode
    char *keyFromFile2 = "songLibrary/sweetChildGR.txt";
    char *keyFile2 = openFile(keyFromFile2);
    char *key2 = filterAndGetKey(keyFile2);
    decode(key2, encrypted);
}
