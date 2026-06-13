#include <stdio.h>

int main(void)
{
    // Get user input
    char result[1000];

    char ch;
    int counter = 0;
    while ((ch = getchar()) != '\n')
    {
        if (ch == '\n')
        {
            result[counter] = ' ';
        }

        else
        {
            result[counter] = ch;
        }

        counter++;
    }

    result[counter] = '\0';

    int i = 0;
    
    printf("Hi,there,");
    while (result[i] != '\0')
    {
        printf("%c", result[i]);
        i++;
    }
    printf("!\n");
}