#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    char *a;
    char str[80];

    for(int i = 0; i<= 6; i++){
        sprintf(str, "%c%d%c", '[',i,']');
    //    fputs(str, stdout);

    }

const int MAX_BUFF = 1000;
char* Buffer = malloc(MAX_BUFF);
int length = 0;
int c = 56;

length += snprintf(Buffer + length, MAX_BUFF-length,
                    "%c%d%c", '[',345,']');
length += snprintf(Buffer + length, MAX_BUFF-length,
                    "%c%d%c", '[',539,']');
length += snprintf(Buffer + length, MAX_BUFF-length,
                    "%c", c);

printf("%s", Buffer);
}
