#include <stdio.h>

int main()  
{
     
    char str1[] = "Chao \0";
    char str2[] = "thay!\0";
    char result[50]; 

    int i = 0, j = 0;

    while (str1[i] != '\0')  
    {
        result[i] = str1[i];
        i++;
    }

    while (str2[j] != '\0') 
    {
        result[i] = str2[j];
        i++;
        j++;
    }

    result[i] = '\0';

    printf("Chuoi sau khi noi: %s\n", result);

    return 0;
}
