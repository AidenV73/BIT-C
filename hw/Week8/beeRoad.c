#include <stdio.h>

void addBigNum(int a[], int b[], int result[]);
void print_big(int a[]);

int main(void)
{
    int a, b;
    
    scanf("%d %d", &a, &b);

    if (a > b)
    {
        printf("Error!\n");
        return 1;
    }

    int d[100][50];
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            d[i][j] = 0;
        }
    }
    d[0][0] = 1;
    d[1][0] = 1;

    for (int i = 2; i <= (b - a); i++)
    {
        addBigNum(d[i-1], d[i - 2], d[i]);
    }

    print_big(d[b - a]);
}


// Add big num
void addBigNum(int a[], int b[], int result[])
{
    int carry = 0;
    for (int i = 0; i < 50; i++)
    {
        int n = a[i] + b[i] + carry;
        result[i] = n % 10;
        carry = n / 10;
    }
}

// Print big num
void print_big(int a[])
{
    int last_digit = 0;
    // Find last digit
    for(int i = 49; i >= 0; i--)
    {
        if (a[i] != 0)
        {
            last_digit = i;
            break;
        }
    }

    for (int i = last_digit; i >= 0; i--)
    {
        printf("%d", a[i]);
    }

    printf("\n");
}

