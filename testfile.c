#include <string.h>
#include <stdio.h>


int main()
{
    int j = 0, i = 0;
    char *buff = "dfjh5348rYFDTYUWE@Å¨Å¨78";
    char buff_02[5000];
while (i != strlen (buff))
{
    if (((buff[i] >= 65) && (buff[i] <= 90)) || ((buff[i] >= 97) && (buff[i] <= 122)))
    {
        buff_02[j] = buff[i];
        i++;
        j++;
    }
    else
    {
        i++;
    }
}
for(int i = 0; i <= sizeof(buff_02); i++)
{
    printf("%c", buff_02[i]);
}
}
