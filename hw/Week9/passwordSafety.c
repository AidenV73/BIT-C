#include <stdio.h>
#include <string.h>

int checkSafety(char password[15]);
int lengthSmallThanSix(char password[15]);
int countCharType(char password[15]);

int main(void)
{
    int n;

    scanf("%d", &n);

    char password[n][50];

    // Clean "\n"
    getchar();

    for (int i = 0; i < n; i++)
    {
        fgets(password[i], sizeof(password[i]), stdin);
        password[i][strcspn(password[i], "\n")] = '\0';
    }

    for (int i = 0; i < n; i++)
    {
        int result = checkSafety(password[i]);
        if (result == 0)
        {
            printf("Not Safe");
        }

        else if (result == 1)
        {
            printf("Medium Safe");
        }

        else if (result == 2)
        {
            printf("Safe");
        }

        printf("\n");
    }
}

// Return 0 if not safe, 1 if medium safe, 2 if safe
int checkSafety(char password[])
{
    int count_char_type = countCharType(password);

    if (lengthSmallThanSix(password) == 1 || count_char_type == 1)
    {
        return 0;
    }

    else if (count_char_type == 2)
    {
        return 1;
    }

    else if (count_char_type > 2)
    {
        return 2;
    }

    return -1;
}

// Check password length, if length < 6 return 1, else return 0
int lengthSmallThanSix(char password[15])
{
    int length = 0;
    while (password[length] != '\0')
    {
        length += 1;
    }

    if (length < 6)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

// Return count of char type in password ({0~9}, {a-z, A-Z}, {else})
int countCharType(char password[])
{
    int count = 0;
    int has_number = 0;
    int has_big_alpha = 0;
    int has_small_alpha = 0;
    int has_symbol = 0;
    for (int i = 0; i < 50; i++)
    {
        char c = password[i];
        // Reached end 
        if (c == '\0')
        {
            break;
        }

        // If password[i] is number
        else if (c >= 48 && c <= 57)
        {
            has_number = 1;
        }

        // If password[i] is alphabet
        else if (c >= 'a' && c <= 'z')
        {
            has_small_alpha = 1;
        }

        else if (c >= 'A' && c <= 'Z')
        {
            has_big_alpha = 1;
        }

        else
        {
            has_symbol = 1;
        }
    }

    count = has_number + has_small_alpha + has_big_alpha + has_symbol;

    return count;
}