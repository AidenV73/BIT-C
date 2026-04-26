#include <stdio.h>

int main(void)
{
    // Get user input
    int n1, n2;
    char operation;
    printf("");
    scanf("%d %c %d", &n1, &operation, &n2);

    int ans = 0;

    switch (operation)
    {
        case '+':
            ans = n1 + n2;
            printf("%d\n", ans);
            break;
        case '-':
            ans = n1 - n2;
            printf("%d\n", ans);
            break;
        case '*':
            ans = n1 * n2;
            printf("%d\n", ans);
            break;
        case '/':
            ans = n1 / n2;
            printf("%d\n", ans);
            break;
    }

    return 0;

}