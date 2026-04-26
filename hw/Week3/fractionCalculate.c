#include <stdio.h>
#include <stdlib.h>

int findGCD(int numerator, int denominator);

int main(void) 
{
    // Get user input
    int numerator1, denominator1; 
    char operator;
    int numerator2, denominator2;

    scanf("%d/%d %c %d/%d", &numerator1, &denominator1, &operator, &numerator2, &denominator2);

    int numerator, denominator;
    // Calculate the fraction 
    if ((numerator1 == numerator2) && (denominator1 == denominator2) && (operator == '-'))
    {
        printf("%d/%d - %d/%d = 0\n", numerator1, denominator1, numerator2, denominator2);
        return 1;
    }
    // While op is '+' and '-'
    switch (operator){
        case '+':
            if (denominator1 == denominator2)
            {
                numerator = numerator1 + numerator2;
                denominator = denominator1;
            }
            else
            {
                int new_numerator1 = numerator1 * denominator2;
                int new_numerator2 = numerator2 * denominator1;
                denominator = denominator1 * denominator2;
                numerator = new_numerator1 + new_numerator2;
            }
            break;
        case '-':
           if (denominator1 == denominator2)
            {
                numerator = numerator1 - numerator2;
                denominator = denominator1;
            }
            else
            {
                int new_numerator1 = numerator1 * denominator2;
                int new_numerator2 = numerator2 * denominator1;
                denominator = denominator1 * denominator2;
                numerator = new_numerator1 - new_numerator2;
            } 
            break;
        case '*':
            numerator = numerator1 * numerator2;
            denominator = denominator1 * denominator2;
            break;
        case '/':
            numerator = numerator1 * denominator2;
            denominator = denominator1 * numerator2;
            break;
    }

    // Simplest the fraction
    int factor;
    if (numerator >= denominator)
    {
        if (numerator % denominator == 0)
        {
            printf("%d/%d %c %d/%d = %d\n", numerator1, denominator1, operator, numerator2, denominator2, numerator/denominator);
            return 0;
        }
        factor = findGCD(numerator, denominator);
    }
    else 
    {
        factor = findGCD(denominator, numerator);
    }

    numerator  = numerator / factor;
    denominator = denominator / factor;

    printf("%d/%d %c %d/%d = %d/%d\n", numerator1, denominator1, operator, numerator2, denominator2, numerator, denominator);
}

int findGCD(int big, int small) 
{
    big = abs(big);
    small = abs(small);
    while (big % small != 0) 
    {
        int new = big % small;
        big = small;
        small = new;
    }
    return small;
}

