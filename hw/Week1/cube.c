#include <stdio.h>

int main(void) 
{
    // Get user input
    int num;
    scanf("%d", &num);

    // Calculate cube of num
    int cube_num = num * num * num;

    // Print out the result
    printf("%d\n", cube_num);
    return 0;
}