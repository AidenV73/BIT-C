#include <stdio.h>

int main(void) 
{
    // Get user input
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    // Find the minimum
    int min_num;
    if (num1 > num2) 
    {
        min_num = num2;
    }

    else
    {
        min_num = num1;
    }

    // Print the min
    printf("min=%d\n", min_num);

    return 0;
}