/*
*Headerfile for homeexam 2 pg3400
*secretCoder for encoding and decoding
*/

int size;

int *openFile(char *filename);
char* filterAndGetKey(int *keyFile);
int findN(int currentCharToEncrypt, char *key, int n);
char* findIndexAndAdd(int *messageToBeEncrypted, int size, char *key);
char* encryptText(char *key, char *message);
char* encode(char *messageFile, char *keyFromFile);
