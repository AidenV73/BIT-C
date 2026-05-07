#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[100];
    scanf("%s", a);

    int len = strlen(a);

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (a[j + 1] > a[j])
            {
                char tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }

    printf("%s\n", a);

    return 0;
}