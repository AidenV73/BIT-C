#include <stdio.h>
#include <string.h>

int isRecursive(char word[], int start, int end, int midLen);

int main(void)
{
    char word[100];
    scanf("%s", word);

    int len = strlen(word);
    int midLen = (len + 1) / 2;
    int result = isRecursive(word, 0, len - 1, midLen);

    if (result == 1)
    {
        printf("Yes\n");
        return 0;
    }
    printf("No\n");
    return 1;
}

// Return 1 if a word is recursive (ewe, level)
int isRecursive(char word[], int start, int end, int midLen)
{
    if (start > midLen || end < midLen)
    {
        return 1;
    }

    else if (word[start] != word[end])
    {
        return 0;
    }

    return isRecursive(word, start + 1, end - 1, midLen);
}