#include <stdio.h>

int isNum(char ch);
int isOp(char ch);

int main(void)
{
    char ch;

    // Arr to save num
    int arr[50] = {0};

    // Ptr to get the latest num
    int ptr = 0;

    // Save the current num
    int current = 0;

    // If there is number not end yet
    int has_num = 0;

    while ((ch = getchar()) != '\n')
    {
        // If ',' then continue
        if (ch == ' ')
        {
            if (has_num == 1)
            {
                // Number ends
                arr[ptr] = current;
                ptr++;
                current = 0;
                has_num = 0;
            }
            continue;
        }
        // If number then put into arr and ptr + 1
        else if (isNum(ch) == 1)
        {
            current = (current * 10) + (ch - '0');
            has_num = 1;
        }
        // If op then take out last two num and calculate, put back result into arr
        else if (isOp(ch) == 1)
        {
            // Take out last two number 
            int num1 = arr[ptr - 1];
            arr[ptr - 1] = 0;
            ptr--;
            int num2 = arr[ptr - 1];
            arr[ptr - 1] = 0;
            ptr--;

            // Calculate ans depends on diff op
            int ans;
            switch (ch)
            {
                case '+':
                    ans = num2 + num1;
                    break;
                case '-':
                    ans = num2 - num1;
                    break;
                case '*':
                    ans = num2 * num1;
                    break;
                case '/':
                    ans = num2 / num1;
                    break;
                case '%':
                    ans = num2 % num1;
                    break;
            }

            // Put ans back into arr
            arr[ptr] = ans;
            ptr++;
        }

        // If have other symbol then quit (like '\n')
        else 
        {
            break;
        }
    }

    printf("%d\n", arr[0]);
    return 0;
}

int isNum(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return 1;
    }

    return 0;
}

int isOp(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
    {
        return 1;
    }

    return 0;
}