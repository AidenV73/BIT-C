#include <stdio.h>

int fun1(int a, int b);
int fun2(int a, int b);

int main(void)
{
    int a, b;
    scanf("%d,%d", &a, &b);

    int gcd = fun1(a, b);
    int lcm = fun2(a, b);

    printf("最大公约数：%d\n", gcd);
    printf("最小公倍数：%d\n", lcm);
}

// Return gcd of a and b
int fun1(int a, int b)
{
    // Make a become bigger num
    if (a < b)
    {
        int tmp = b;
        b = a;
        a = tmp;
    }

    while (a % b != 0)
    {
        int mod = a % b;
        a = b;
        b = mod;
    }

    return b;
}

// Return lcm of a and b
int fun2(int a, int b)
{
    int gcd = fun1(a, b);

    int result = (a * b) / gcd;

    return result;
}