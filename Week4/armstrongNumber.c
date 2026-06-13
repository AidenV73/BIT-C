#include <stdio.h>

int isArmstrong(int n, int digit_count);

int main(void)
{
    // Get user input
    int n;
    scanf("%d", &n);

    // Decide digit
    int loop_time = 1;

    // Have output
    int have_output = 0;

    for (int _ = 0; _ < n; _++)
    {
        loop_time = loop_time * 10;
    }

    // Loop to find number
    for (int i = (loop_time / 10); i < loop_time; i ++)
    {
        if (isArmstrong(i, n) == 1)
        {
            printf("%d\n", i);
            have_output = 1;
        }
    }

    if (have_output == 0) 
    {
        printf("No output.\n");
        return 1;
    }
    
    return 0;
}

int isArmstrong(int n, int digit_count)
{

    int num = n;
    int value = 0;

    // Seperate number
    while(num > 0)
    {
        int tmp = num % 10;
        num = num / 10;

        int power = 1;
        for (int i = 0; i < digit_count; i++)
        {
            power *= tmp;
        }

        value += power;
    }

    if (value == n)
    {
        return 1;
    }
    
    return 0;
}