#include <stdio.h>
#include <stdlib.h>

long findGCD(long numerator, long denominator);

int main(void) 
{
    // Get user input
    long numerator1, denominator1; 
    char operator;
    long numerator2, denominator2;

    scanf("%ld/%ld %c %ld/%ld", &numerator1, &denominator1, &operator, &numerator2, &denominator2);

    long numerator, denominator;
    // Calculate the fraction 
    if ((numerator1 == numerator2) && (denominator1 == denominator2) && (operator == '-'))
    {
        printf("%ld/%ld - %ld/%ld = 0\n", numerator1, denominator1, numerator2, denominator2);
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
                long new_numerator1 = numerator1 * denominator2;
                long new_numerator2 = numerator2 * denominator1;
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
                long new_numerator1 = numerator1 * denominator2;
                long new_numerator2 = numerator2 * denominator1;
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
    long factor;
    if (numerator >= denominator)
    {
        if (numerator % denominator == 0)
        {
            printf("%ld/%ld %c %ld/%ld = %ld\n", numerator1, denominator1, operator, numerator2, denominator2, numerator/denominator);
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

    printf("%ld/%ld %c %ld/%ld = %ld/%ld\n", numerator1, denominator1, operator, numerator2, denominator2, numerator, denominator);
}

long findGCD(long big, long small) 
{
    big = labs(big);
    small = labs(small);
    while (big % small != 0) 
    {
        long new = big % small;
        big = small;
        small = new;
    }
    return small;
}