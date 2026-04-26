#include <stdio.h>

int find_left(int count, int num, int students[count]);
void eliminate_child(int count, int num, int students[count]);

int main(void)
{
    int count;

    int number;

    scanf("%d %d", &count, &number);

    int students[count];

    for (int i = 0; i < count; i++)
    {
        students[i] = 1;
    }

    int left_index = find_left(count, number, students);

    printf("The left child is NO.%d\n", left_index);
    return 0;
}


// Find left child
int find_left(int count, int num, int students[count])
{
    eliminate_child(count, num, students);

    int index;

    for(int i = 0; i < count; i++)
    {
        if (students[i] == 1)
        {
            index = i + 1;
            break;
        }
    }

    return index;
}


// Eliminate child
void eliminate_child(int count, int num, int students[count])
{
    int counter = 0;
    int remain = count;

    int ptr = 0;
    while (remain != 1)
    {
        if (students[ptr] == 1)
        {
            counter += 1;
            if (counter == num)
            {
                // Eliminate
                students[ptr] = 0;
                counter = 0;
                remain -= 1;
            }
        }

        ptr += 1;

        // If reached end then go back 
        if (ptr > count)
        {
            ptr = 0;
        }
    }
}