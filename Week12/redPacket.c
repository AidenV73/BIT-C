#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findIndex(char name[], char *names[]);

int main(void)
{
    int count;

    scanf("%d", &count);

    // Initialize arr to store names
    char *names[count + 1];

    // Get name info
    for (int i = 0; i < count; i++)
    {
        names[i] = (char *)malloc(15 * sizeof(char));
        if (names[i] == NULL)
        {
            return 1;
        }
        scanf("%14s", names[i]);
    }

    // Sentinel 
    names[count] = NULL;

    // Initialize balance

    int balance[count];

    for (int i = 0; i < count; i++)
    {
        balance[i] = 0;
    }

    for (int i = 0; i < count; i++)
    {
        char name[15];
        scanf("%14s", name);
        int current = findIndex(name, names);
        int money, seperate_count;
        scanf("%d %d", &money, &seperate_count);

        if (seperate_count == 0)
        {
            continue;
        }
        
        int money_for_each = money / seperate_count;
        balance[current] -= money;
        balance[current] += money % seperate_count;        

        // Give money to each ppl
        for (int i = 0; i < seperate_count; i++)
        {
            scanf("%14s", name);
            int current = findIndex(name, names);
            balance[current] += money_for_each;
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%s %d\n", names[i], balance[i]);
    }
}   

// Return index in names
int findIndex(char name[], char *names[])
{
    int i = 0;
    while (names[i] != NULL)
    {
        if (strcmp(name, names[i]) == 0)
        {
            break;
        }
        i++;
    }
    return i;
}