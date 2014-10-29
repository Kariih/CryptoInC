#include <string.h>
#include <stdio.h>


int main()
{
    char *a[255];

    for(int i = 0; i<= 6; i++){
        a[i] = sprintf(a[i], "%c%d%c", '[',i,']');
    }

    for(int i = 0; i<= 6; i++){
        printf("%s\n", a[i]);
    }

}
