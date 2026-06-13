#include <stdio.h>

int main(void) 
{
    // Get user input
    int num1, num2;
    scanf("%d", &num1);

    printf("");
    scanf("%d", &num2);

    // Get sum of two num
    int sum = num1 + num2;

    // Print out the result
    printf("%d+%d=%d\n", num1, num2, sum);
    
    return 0;
}