#include <stdio.h>

int main(void) 
{
    // Check user input
    char a;
    scanf("%c", &a);

    if (a >= 97 && a <= 122)
    {
        a = a - 32;
    }

    else if (a >= 65 && a <= 90)
    {
        a = a + 32;
    }

    printf("%c\n", a);
    
    return 0;
}