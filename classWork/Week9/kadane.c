#include <stdio.h>

int kadane(int len, int nums[]);
int max(int a, int b);

int main(void)
{
    int nums[100];
    int len = 0;

    for (int i = 0; i < 100; i++)
    {
        int n;
        scanf("%d", &n);

        if (n == 0)
        {
            break;
        }

        else
        {
            nums[i] = n;
            len++;
        }
    }

    int max = kadane(len, nums);

    printf("%d\n", max);
}

int kadane(int len, int nums[])
{
    int current_max = nums[0];
    int global_max = nums[0];

    for (int i = 1; i < len; i++)
    {
        current_max = max(nums[i] + current_max, current_max);
        global_max = max(current_max, global_max);
    }

    return global_max;
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }

    return b;
}