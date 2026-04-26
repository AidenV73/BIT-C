#include <stdio.h>

int calculateHeight(int n);
void printSymbol(int n, char c);
void printSpace(int n);

int main(void)
{
    int n;
    char symbol;
    
    scanf("%d %c", &n, &symbol);

    int height = calculateHeight(n);
    
    // Print top
    for (int i = 0; i < ((height / 2) + 1); i++)
    {
        int symbol_count = (height - (2 * i));
        printSpace(i);
        printSymbol(symbol_count ,symbol);
        printf("\n");
        n -= symbol_count;
    }

    // Print bottom
    for (int i = 0; i < (height / 2); i++)
    {
        int symbol_count = (2 * i) + 3;
        printSpace((height / 2) - (i + 1));
        printSymbol(symbol_count, symbol);
        printf("\n");
        n -= symbol_count;
    }

    printf("%d\n", n);

    return 0;
}

// Return height of the sand glass
int calculateHeight(int n)
{
    if (n < 1)
    {
        return 0;
    }
    int height = 1;
    int factor = 1;
    int current_num = (2 *((2 * factor) + 1));
    while (n > current_num)
    {
        n -= current_num;
        factor += 1;
        current_num = (2 *((2 * factor) + 1));
        height += 2;
    }

    return height;
}

// Print symbol "c" n times
void printSymbol(int n, char c)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", c);
    }
}

// Print "space" n times
void printSpace(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

