#include <stdio.h>
#include <string.h>

void textCompress(int element_count, char text[100][80]);
int isChar(char ch);

int main(void)
{
    char text[100][80];

    memset(text, 0, sizeof(text));

    char ch;
    int element_count = 0;
    int word_count = 0;
    int alphabet_count = 0;

    while ((ch = getchar()) != EOF)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            text[element_count][alphabet_count] = ch;
            alphabet_count++;
        }

        else 
        {
            if (alphabet_count > 0)
            {
                text[element_count][alphabet_count] = '\0';
                element_count += 1;
                alphabet_count = 0;       
            }

            text[element_count][0] = ch;
            text[element_count][1] = '\0';
            element_count++;
        }
    }

    // Last word
    if (alphabet_count > 0)
    {
        text[element_count][alphabet_count] = '\0';
        element_count += 1;
    }
    

    // Find same word and replace
    textCompress(element_count, text);

    for (int i = 0; i < element_count; i++)
    {
        printf("%s", text[i]);
    }

    return 0;
}

void textCompress(int element_count, char text[100][80])
{
    int word_index = 1;
    for (int i = 0; i < element_count; i++)
    {
        if (isChar(text[i][0]) == 0)
        {
            continue;
        }

        for (int j = i + 1; j < element_count; j++)
        {
            if (isChar(text[j][0]) == 0)
            {
                continue;
            }

            // If found same word then change word into i
            if (strcmp(text[i], text[j]) == 0)
            {
                text[j][0] = word_index + '0';
                text[j][1] = '\0';
            }
        }
        word_index++;
    }
}

int isChar(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        return 1;
    }

    return 0;
}

