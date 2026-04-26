#include <stdio.h>

void sortArray(int array[10]);
void insertArray(int array[10], int n);

int main(void)
{
    int first[10] = {0};
    int n;

    int counter = 0;
    int has_num = 0;

    while (counter < 9)
    {
        char ch = getchar();
        if (ch >= '0' && ch <= '9')
        {
            first[counter] = first[counter] * 10 + ch - '0';
            has_num = 1;
        }

        else 
        {
            if (has_num == 1)
            {
                counter += 1;
                has_num = 0;
            }
        }
    }

    scanf(" %d", &n);

    sortArray(first);

    insertArray(first, n);

    for (int i = 0; i < 9; i++)
    {
        printf("%d,", first[i]);
    }

    printf("%d\n", first[9]);
    return 0;
}

void sortArray(int array[10])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (array[i] > array[j])
            {
                int tmp = array[j];
                array[j] = array[i];
                array[i] = tmp;
            }
        }
    }
}

void insertArray(int array[10], int n)
{
    int index = 9;
    for (int i = 0; i < 9; i++)
    {
        int current_num = array[i];
        int next_num = array[i + 1];
        if (n <= current_num)
        {
            index = i;
            break;
        }
    }

    for (int i = 9; i > index; i--)
    {
        array[i] = array[i - 1];
    }

    array[index] = n;
}