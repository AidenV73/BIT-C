#include <stdio.h>

int main(void)
{
    int n = 0;

    int max = -111;
    int min = 111;

    char ch;
    char op, equalOp;
    int has_num = 0;
    int has_symbol = 0;
    while ((ch = getchar()) != '\n')
    {
        // If ch is number
        if ((ch >= '0') && (ch <= '9'))
        {
            n = (n * 10) + (ch - '0');
            has_num = 1;
        }
        
        else 
        {
            // Number ends
            if (has_num == 1)
            {
                if (n > max)
                {
                    max = n;
                }
                if (n < min)
                {
                    min = n;
                }
                n = 0;
                has_num = 0;
            }

            else 
            {
                // If has op then break and scan '='
                if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '%'))
                {
                    op = ch;
                    break;
                }

                else if (ch == ',')
                {
                    continue;
                }

                else
                {
                    has_symbol = 1;
                    break;
                }
            }
        }
    }

    if (has_symbol == 1)
    {
        printf("Error!\n");
        return 3;
    }

    // Scan equal 
    scanf(",%c", &equalOp);

    if ((op == '/') && (min == 0))
    {
        printf("Error!\n");
        return 1;
    }

    if (equalOp != '=')
    {
        printf("Error!\n");
        return 2;
    }

    int ans = 0;

    switch (op)
    {
        case '+':
            ans = max + min;
            printf("%d+%d=%d\n", max, min, ans);
            break;
        case '-':
            ans = max - min;
            printf("%d-%d=%d\n", max, min, ans);
            break;
        case '*':
            ans = max * min;
            printf("%d*%d=%d\n", max, min, ans);
            break;
        case '/':
            ans = max / min;
            printf("%d/%d=%d\n", max, min, ans);
            break;
        case '%':
            ans = max % min;
            printf("%d%c%d=%d\n", max, op, min, ans);
            break;
    }

    return 0;
}