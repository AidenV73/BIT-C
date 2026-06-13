#include <stdio.h>

void subNumber(int n, int result[3]);

int main(void)
{
    int k;

    scanf("%d", &k);

    int result[3];
    subNumber(12345, result);
    for (int i = 10000; i <= 30000; i++)
    {
        int result[3];
        subNumber(i, result);
        if ((result[0] % k) == 0 && (result[1] % k) == 0 && (result[2] % k) == 0)
        {
            printf("%d\n", i);
        }
    }
}

void subNumber(int n, int result[3])
{
    result[0] = n / 100;    
    result[1] = (n / 10) % 1000;
    result[2] = (n % 1000);
}
