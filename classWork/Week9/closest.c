#include <stdio.h>
#include <stdlib.h>

void sortArr(int len, int arr[], int index[]);
int min(int a, int b);

int main(void)
{
    int len_a, len_b;
    scanf("%d %d", &len_a, &len_b);

    int arr_a[len_a];
    int arr_b[len_b];
    int index_b[len_b];
    int target = 0;

    // Get arr_a 
    for (int i = 0; i < len_a; i++)
    {
        scanf("%d", &arr_a[i]);
        target += arr_a[i];
    }

    // Get arr_b
    for (int i = 0; i < len_b; i++)
    {
        scanf("%d", &arr_b[i]);
    }

    int arr[len_b + 1];
    int index[len_b];
    arr[0] = 0;
    int current_sum = 0;
    for (int i = 0; i < len_b; i++)
    {
        current_sum += arr_b[i];
        arr[i + 1] = current_sum;
        index[i] = i + 1;
    }

    // sort arr
    sortArr(len_b, arr, index);

    int min_differ = target;
    int start = 0;
    int end = 0;

    for (int i = 1; i < len_b + 1; i++)
    {
        for (int j = i + 1; j < len_b + 1; j++)
        {
            int differ = abs((arr[j] - arr[i]) - target);
            if (differ < min_differ)
            {
                min_differ = differ;
                start = i;
                end = j;
            }
        }
    }

    if (end == 0)
    {
        printf("%d\n", arr_b[start]);
        return 0;
    }
    printf("%d %d\n", arr_b[start], arr_b[end - 1]);
}

// Sort arr and also keep track on index
void sortArr(int len, int arr[], int index[])
{
    for (int i = 1; i < len; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap element
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;

                // Swap index
                int tmpIndex = index[j];
                index[j] = index[j + 1];
                index[j + 1] = tmpIndex;
            }
        }
    }
}
// Return the smaller int
int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }

    return a;
}