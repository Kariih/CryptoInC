#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <ctype.h>

char *charToBeEncrypted;
char *charForKey;

int openFile(){
    char *filename = "songLibrary/anaconda.txt";
    FILE *file = fopen(filename, "r");
    struct stat st;
    stat(filename, &st);
    int size = st.st_size;
    charForKey = malloc(size*sizeof(char));
    int count = 0;
    int charFromFile = 0;
    while (fscanf(file, "%d", &charFromFile) == 1)
    {
        charForKey[count] = charFromFile;
        count++;
    }
    return count;
}
void print(char *charForKey, int count)
{


}
char* filterAndGetKey(char *charForKey, int count)
{
    char *filteredText;
    for(int i = 0; charForKey[i]!='\0'; i++)
    {
        filteredText = tolower(&charForKey[i]);
    }
    for(int i=0; filteredText[i]!='\0'; ++i)
    {
        while (!(filteredText[i]>='a'&&filteredText[i]<='z') || filteredText[i]=='\0')
        {
            for(int j=i;filteredText[j]!='\0';++j)
            {
                filteredText[j]=filteredText[j+1];
            }
            filteredText[i]='\0';
        }
    }
    for(int i = 0; filteredText[i]!='\0'; i++)
    {
        printf("%c", filteredText[i]);
    }
    return filteredText;
}
void encrypt(){
    printf("%s", "this will be encrypted");
}
int main(){
    char Alphabet[26] = {"abcdefghijklmnopqrstuvwxyz"};

    int count = 0;
    count = openFile();
//    print(charToBeEncrypted, count);
    filterAndGetKey(charForKey, count);
//    encrypt();

}
