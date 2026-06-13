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
            break;
        case '-':
            ans = n1 - n2;
            break;
        case '*':
            ans = n1 * n2;
            break;
        case '/':
            ans = n1 / n2;
            break;
        case '%':
            ans = n1 % n2;
            break;
    }
    printf("%d\n", ans);

    return 0;

}