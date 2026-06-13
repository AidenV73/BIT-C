#include <stdio.h>

int main(void)
{
    // Get user input
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    // Calculate 
    int sum = num1 + num2;
    int minus = num1 - num2;
    int multiply = num1 * num2;
    int divide = num1 / num2;
    int mod = num1 % num2;

    // Print result
    printf("%d+%d=%d\n", num1, num2, sum);
    printf("%d-%d=%d\n", num1, num2, minus);
    printf("%d*%d=%d\n", num1, num2, multiply);
    printf("%d/%d=%d\n", num1, num2, divide);
    printf("%d%%%d=%d\n", num1, num2, mod);

    return 0;
}