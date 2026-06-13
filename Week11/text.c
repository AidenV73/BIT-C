#include <ctype.h>
#include <stdio.h>
#include <string.h>

int find_word(char *s, char words[][80], int count);

int main(void)
{
    char words[5000][80];
    int count = 0;
    char line[1000];
    while (fgets(line, sizeof(line), stdin))   
    {
        int i = 0; 
        int len = strlen(line);

        while (i < len)
        {
            if (!isalpha(line[i]))
            {
                putchar(line[i]);
                i++;
            }

            else 
            {
                char word[5000];
                int j = 0;
                while (i < len && isalpha(line[i]))
                {
                    word[j] = line[i];
                    j++;
                    i++;
                }
                word[j] = '\0';

                int exist = find_word(word, words, count);

                if (exist == 0)
                {
                    strcpy(words[count], word);
                    count++;
                    printf("%s", word);
                }

                else 
                {
                    printf("%d", exist);
                }
            }
        }
    }
}

int find_word(char *s, char words[][80], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(s, words[i]) == 0)
        {
            return i + 1;
        }
    }
    return 0;
}