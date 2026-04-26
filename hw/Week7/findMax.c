#include <stdio.h>

int main(void)
{
    // Get user input
    int n;
    scanf("%d", &n);
    
    char a[12];
    int i = 0;

    // Make it an array and find max
    while (n > 0)
    {
        a[i] = (n % 10) + '0';
        n = n / 10;
        i += 1;
    }

    a[i] = '\0';

    for (int j = 0; j < i; j++)
    {
        for (int k = j; k < i; k++)
        {
            if (a[j] < a[k])
            {
                char tmp = a[j];
                a[j] = a[k];
                a[k] = tmp;
            }
        }
    }

    printf("%s\n", a);

    return 0;
}