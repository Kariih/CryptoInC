/*
*Headerfile for homeexam 2 pg3400
*secretCoder for encoding and decoding
*/

int size;

char *openFile(char *filename);
char* filterAndGetKey(char *keyFile);
int findN(int currentCharToEncrypt, char *key, int n);
char* findIndexAndAdd(char *messageToBeEncrypted, int size, char *key);
char* encryptText(char *key, char *message);
char* encode(char *messageFile, char *keyFromFile);
