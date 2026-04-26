#include <stdio.h>

void encode(int length, int code[10], int result[10]);
int encodeProcess(int i, int code[10]);
void decode(int length, int code[10], int result[10]);

int main(void)
{
    int way, length;
    int code[10];

    scanf("%d %d", &way, &length);

    for (int i = 0; i < length; i++)
    {
        scanf("%d", &code[i]);
    }

    int result[10];

    // Encoding
    if (way == 1)
    {
        encode(length, code, result);
    }

    else if (way == 2)
    {
        decode(length, code, result);
    }

    for (int i = 0; i < length; i++)
    {
        printf("%d ", result[i]);
    }

    printf("\n");

}

// Encode array
void encode(int length, int code[10], int result[10])
{
    result[0] = 0;
    for (int i = 1; i < length; i++)
    {
        result[i] = encodeProcess(i, code);
    }
}

// Decode array
void decode(int length, int code[10], int result[10])
{
    // Do a array from 0 ~ length - 1
    int available[10];
    for (int i = 0; i < length; i++)
    {
        available[i] = i;
    }

    // Decode from back to front
    int tmp_result[length];

    for (int i = 0; i < length; i++)
    {
        int index = code[length - 1 - i];
        tmp_result[i] = available[index];

        // Remove available[code[length - 1] - i]

        for (int j = index; j < length; j++)
        {
            available[j] = available[j + 1];
        }
    }

    // result = reversed temp
    for (int i = 0; i < length; i++)
    {
        result[i] = tmp_result[length - i - 1];
    }
}

// Encode number at index i
int encodeProcess(int i, int code[10])
{
    // Get current num
    int current_num = code[i];

    int counter = 0;
    // Check how many number is smaller than current_num
    for (int j = 0; j < i; j++)
    {
        if (current_num > code[j])
        {
            counter += 1;
        }        
    }

    return counter;
}



