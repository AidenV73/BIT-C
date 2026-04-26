#include <stdio.h>

int main(void) 
{
    // Get user input
    int length1, length2, length3;
    scanf("%d %d %d", &length1, &length2, &length3);

    // If it is triangle
    if (((length1 + length2) > length3) && ((length1 + length3) > length2) && ((length2 + length3) > length1)) 
    {
        // If two side length are same(isoceles triangle)
        if ((length1 == length2 || length1 == length3 || length2 == length3))
        {
            // If three side length are same
            if ((length1 == length2) && (length2 == length3))
            {
                printf("equilateral triangle.\n");
                return 0;
            }

            else 
            {
                printf("isoceles triangle.\n");
                return 0;
            }
        }

        // Just normal triangle
        else
        {
            printf("triangle.\n");
            return 0;
        }
    }

    // Not a triangle
    else 
    {
        printf("non-triangle.\n");
        return 0;
    }
}