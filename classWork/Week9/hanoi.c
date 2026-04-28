#include <stdio.h>

int hanoi(int n);

int main(void)
{
    int n;
    scanf("%d", &n);

    int result = hanoi(n);

    printf("%d\n", result);
}

// Move all disk from a -> c or c -> a
int hanoi(int n)
{
    int count = 0;
    if (n == 1)
    {
        return 2;
    }

    else 
    {
        // Move (n - 1) disk to last
        count += hanoi(n - 1);

        // Move 1 disk to mid
        count++;

        // Move (n - 1) disk to first
        count += hanoi(n - 1);

        // Move 1 disk to last
        count++;

        // Move (n - 1) disk to last
        count += hanoi(n - 1);
    }
    
    return count;

}