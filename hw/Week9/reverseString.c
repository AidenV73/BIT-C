/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <stdlib.h>  

void reverse(char str[], int, int); 
int countLength(char str[]);

int main( )  
{   char str[100];  
    int start, end;  
    gets(str);  
    scanf("%d%d", &start, &end);  
    reverse( str, start, end );  
    printf("%s\n", str);  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  

void reverse(char str[], int start, int end)
{
    int arrayLength = countLength(str);

    if (start >= end)
    {
        return;
    }

    else if (end >= arrayLength)
    {
        reverse(str, start, end - 1);
    }

    else if (start < 0)
    {
        return;
    }

    else 
    {
        char tmp;
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        reverse(str ,start + 1, end - 1);
    }
}

int countLength(char str[])
{
    int counter = 0;
    while (str[counter] != '\0')
    {
        counter += 1;
    }

    return counter;
}


