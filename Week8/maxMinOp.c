#include <stdio.h>

int main(void)
{
    int firstNum;

    scanf("%d", &firstNum);

    int max = firstNum;
    int min = firstNum;

    int n;
    while (scanf(",%d", &n) == 1)
    {
        if (n > max)
        {
            max = n;
        }

        if (n < min)
        {
            min = n;
        }
    }

    char op;
    scanf("%c", &op);

    char equalSign;
    scanf(",%c", &equalSign);

    printf("DEBUG:%c, %c", op, equalSign);
    
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

    if (equalSign != '=')
    {
        printf("Error!\n");
        return 1;
    }

    if (max < 0)
    {
        printf("(%d) ", max);
    }
    else 
    {
        printf("%d ", max);
    }

    printf("%c ", op);

    if (min < 0)
    {
        printf("(%d) ", min);
    }
    else 
    {
        printf("%d ", min);
    }
    printf("= %d\n", ans);

}