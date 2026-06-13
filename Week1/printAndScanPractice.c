#include <stdio.h>

int main(void) 
{
    // Get user input
    int num;
    scanf("%d", &num);

    // Print user input by different carry system
    printf("x=%d,x=%o,x=%x\n", num, num, num);
    return 0;
}