/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <stdlib.h>  

void reverse(char str[100], int start, int end); 
int countLength(char str[100]);

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

void reverse(char str[100], int start, int end)
{
    int arrayLength = countLength(str);

    if (start >= end)
    {
        return;
    }

    if (end > arrayLength)
    {
        return;
    }

    if (start < 0)
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

int countLength(char str[100])
{
    int counter = 0;
    while (str[counter] != '\0')
    {
        counter += 1;
    }

    return counter;
}


