#include <stdio.h>

void seperateNum(int n);

int main(void)
{
    int n;

    scanf("%d", &n);
    
    seperateNum(n);
}


void seperateNum(int n)
{
    if (n <= 1)
    {
        return;
    }

    // If is even then / 2
    if (n % 2 == 0)
    {
        printf("2\n");
        seperateNum(n / 2);
    }
    // If is odd then iterate
    else 
    {
        // Find smallest factor
        int factor = 3;
        while (n % factor != 0)
        {
            // n is prime
            if ((factor * factor) > n)
            {
                printf("%d\n", n);
                return;
            }
            factor += 2;
        }
        printf("%d\n", factor);
        seperateNum(n / factor);
    }
}