#include <stdio.h>

int josephus(int count, int number);

int main(void)
{
    int count, number;

    scanf("%d %d", &count, &number);
    
    int index = josephus(count, number);

    printf("The left child is NO %d.\n", index + 1);
    return 0;
}

// Return index of the last ppl
int josephus(int count, int number)
{
    if (count == 1)
    {
        return 0;
    }

    else
    {
        return (josephus(count - 1, number) + number) % count;
    }
}