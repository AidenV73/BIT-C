#include <stdio.h>

int main(void)
{
    // Get user input (char)
    char c;
    scanf("%c", &c);

    // Print out result
    printf("The ASCII of character '%c' is %d.\n", c, c);
    
    return 0;
}