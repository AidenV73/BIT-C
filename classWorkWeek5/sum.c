#include <stdio.h>

void print_base_recursive(long n, int base);

int main(void)
{
    int numA, numB, base;

    scanf("%d %d %d", &numA, &numB, &base);

    long sum = (long)numA + numB;

    if (sum < 0)
    {
        sum = -sum;
        printf("-");
    }
    print_base_recursive(sum, base);
    printf("\n");
    return 0;
    
}

void print_base_recursive(long n, int base)
{
    if (n >= base)
    {
        print_base_recursive(n / base, base);
    }

    printf("%ld", (n % base));
}


