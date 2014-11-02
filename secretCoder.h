/*
* Headerfile for homeexam 2 pg3400
* secretCoder for encoding and decoding
* The openFile should allways be called first
* The char pointer returned from openFile() is input paramerer to
* key, message.
*/

//int size (of messages, keys) is used all over the program.
int size;

/*
* Open file, both keys and messages.
* Char pointer returned is text readed from file.
* Parameters is char filename string.
*/
char *openFile(char *filename);

/*
* Method for kreating key.
* Parameter is a file of key. Return from open file.
* Returns a plain key for encryption and decryption.
*/
char* filterAndGetKey(char *keyFile);

/*
* Main encode method. Only one that have to be implemented.
* Parameters is messageFile that is opened file
* (return from openFile() and a key (returned from filterAndGetKey()).
* Distance is the difference of indexes in encrypted text.
* Return encrypted text.
*/
char* encode(char *messageFile, char *keyFromFile, int distance);
//other methodes for encryption.
char* encryptText(char *key, char *message, int distance);
char* findIndexAndAdd(char *messageToBeEncrypted, int size, char *key, int distance);
int findN(int currentCharToEncrypt, char *key, int n);

/*
* Method for decryption.
* Parameter is a key (return from filterAndGetKey()) and a encrypted message
* which is returned from encode().
* Return a decoded text.
*/
char* decode(char *key, char *message);

/*
* Print out status for encryption.
* Parameter is name of sourcefile (sourceFileName),
* name of key file (keyFileName) and the encoded message.
* inputType can have following declaration:
* sourceFile = s, keyFileName = k, encryptedMessage = m. ("skm")
*/
void myPrintEncoded(char *inputTypes, char *souceFileName, char *keyFileName, char *encryptedMessage);

/*
* Print out status for encryption.
* Parameter is name of sourcefile (sourceFileName),
* name of key file (keyFileName) and the decoded message.
* inputType can have following declaration:
* keyFileName = k, encryptedMessage = m. ("km")
*/
void myPrintDecoded(char *inputTypes, char *keyFileName, char *decryptedMessage);
