#include <stdio.h>

int main(void)
{
    int firstNum;

    scanf("%d", &firstNum);

    int max = firstNum;
    int min = firstNum;

    int hasEqualSymbol = 0;

    char op;

    while (1)
    {
        // Scan ','
        char ch;
        scanf("%c", &ch);
        if (ch == ',')
        {
            // Number after ','
            int n;
            scanf("%d", &n);
            if (n > max)
            {
                max = n;
            }
            if (n < min)
            {
                min = n;
            }

        }

        else if (ch == '=')
        {
            hasEqualSymbol = 1;
            break;
        }

        else
        {
            op = ch;
        }
    }
    
    int ans = 0;

    switch (op)
    {
        case '+':
            ans = max + min;
            break;
        case '-':
            ans = max - min;
            break;
        case '*':
            ans = max * min;
            break;
        case '/':
            ans = max / min;
            break;
        case '%':
            ans = max % min;
            break;
    }

    if (hasEqualSymbol == 0)
    {
        printf("Error!\n");
        return 1;
    }

    printf("%d%c%d=%d\n", max, op, min, ans);
    return 0;
}