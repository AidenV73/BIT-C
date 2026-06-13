#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char *suit;
    char (*rank)[3];
} Player;

int isLegal(Player *player);
int suitIsLegal(char *suit);
int rankIsLegal(char (*rank)[3]);
int haveSameCard(Player *player1, Player *player2);
void sortCard(Player *player);
int suitCompare(int suitA, int suitB);
int rankCompare(int rankA, int rankB);
int getSuitWeight(int suit);
int getRankWeight(char rank);
void swapCard(Player *player, int i, int j);

int main(void)
{
    Player players[2];

    // Get player info
    for (int i = 0; i < 2; i++)
    {
        players[i].id = i;
        char *suit = (char*)malloc(3 * sizeof(char));
        char (*rank)[3] = (char(*)[3])malloc(3 * sizeof(char[3]));

        if (suit == NULL || (*rank) == NULL)
        {
            return 1;
        }

        for (int j = 0; j < 3; j++)
        {
            scanf(" %c%2s", &suit[j], rank[j]);            
        }

        players[i].suit = suit;
        players[i].rank = rank;
    }

    // Check input legal
    for (int i = 0; i < 2; i++)
    {
        if (isLegal(&players[i]) == -1)
        {
            printf("Input Error!\n");
            return 1;
        }
    }

    // Check if have same card
    if (haveSameCard(&players[0], &players[1]) == 1)
    {
        printf("Input Error!\n");
        return 2;
    }

    // Sort card
    for (int i = 0; i < 2; i++)
    {
        sortCard(&players[i]);
    }

    int ptrA = 0;
    int ptrB = 0;
    while (ptrA < 3 && ptrB < 3)
    {
        char suitA = players[0].suit[ptrA];
        char suitB = players[1].suit[ptrB];
        
        int suitResult = suitCompare(suitA, suitB);

        if (suitResult == 1)
        {
            printf("Winner is A!\n");
            break;
        }

        else if (suitResult == -1)
        {
            printf("Winner is B!\n");
            break;
        }

        else
        {
            int rankResult = rankCompare(players[0].rank[ptrA][0], players[1].rank[ptrB][0]);

            if (rankResult == 1)
            {
                printf("Winner is A!\n");
                break;
            }

            else if (rankResult == -1)
            {
                printf("Winner is B!\n");
                break;
            }

            else
            {
                ptrA++;
                ptrB++;
            }
        }
    }

    if (ptrA == ptrB && ptrA == 3)
    {
        printf("Winner is X!\n");
    }

    // Print sorted A and B
    printf("A:");
    for (int i = 0; i < 3; i++)
    {
        printf(" %c%s", players[0].suit[i], players[0].rank[i]);
    }
    printf("\n");

    printf("B:");
    for (int i = 0; i < 3; i++)
    {
        printf(" %c%s", players[1].suit[i], players[1].rank[i]);
    }
    printf("\n");

    return 0;
}

// Check input legal, if input is legal return 1, else return -1
int isLegal(Player *player)
{
    if (suitIsLegal(player->suit) == 1 && rankIsLegal(player->rank) == 1)
    {
        return 1;
    }

    return -1;
}

// Check if suit is legal (H, S, D, C)
int suitIsLegal(char *suit)
{
    for (int i = 0; i < 3; i++)
    {
        if (suit[i] != 'H' && suit[i] != 'S' && suit[i] != 'D' && suit[i] != 'C')
        {
            return -1;
        }
    }
    return 1;
}

// Check if rank is legal (2 ~ A)
int rankIsLegal(char (*rank)[3])
{
    for (int i = 0; i < 3; i++)
    {
        if (rank[i][0] == '1')
        {
            if (rank[i][1] == '0')
            {
                continue;
            }
        }

        else 
        {
            if (rank[i][0] >= '2' && rank[i][0] <= '9')
            {
                continue;
            }

            else if (rank[i][0] == 'J' || rank[i][0] == 'Q' || rank[i][0] == 'K' || rank[i][0] == 'A')
            {
                continue;
            }

            return -1;
        }
    }
    return 1;
}

// Return 1 if there is same card
int haveSameCard(Player *player1, Player *player2)
{
    // Check player 1
    for (int i = 0; i < 3; i++)
    {
        // Compare itself
        for (int j = i + 1; j < 3; j++)
        {
            int suitResult = suitCompare(player1->suit[i], player1->suit[j]);
            int rankResult = rankCompare(player1->rank[i][0], player1->rank[j][0]);
            if (suitResult == 0 && rankResult == 0)
            {
                return 1;
            }
        }
    }

     // Check player 2
    for (int i = 0; i < 3; i++)
    {
        // Compare itself
        for (int j = i + 1; j < 3; j++)
        {
            int suitResult = suitCompare(player2->suit[i], player2->suit[j]);
            int rankResult = rankCompare(player2->rank[i][0], player2->rank[j][0]);
            if (suitResult == 0 && rankResult == 0)
            {
                return 1;
            }
        }
    }

    return 0;
}

// Sort player's card
void sortCard(Player *player)
{
    // Sort by suit then num
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2 - i; j++)
        {
            int suitResult = suitCompare(player->suit[j], player->suit[j + 1]);
            // If suit smaller then swap
            if (suitResult == -1)
            {
                swapCard(player, j, j + 1);
            }
            // else if equal then compare num
            else if (suitResult == 0)
            {
                int rankResult = rankCompare(player->rank[j][0], player->rank[j + 1][0]);
                // If rank smaller then swap
                if (rankResult == -1)
                {
                    swapCard(player, j, j + 1);
                }
            }
        }
    } 
}

// Return 1 if suit A is greater than suit B, return 0 if equal, return -1 if smaller
int suitCompare(int suitA, int suitB)
{
    int result;
    // Add weight
    int weightA = getSuitWeight(suitA);
    int weightB = getSuitWeight(suitB);

    if (weightA > weightB)
    {
        result = 1;
    }

    else if (weightA == weightB)
    {
        result = 0;
    }

    else
    {
        result = -1;
    }

    return result;
}

// Return 1 if rankA is greater than rank B, return 0 if equal, return -1 if smaller
int rankCompare(int rankA, int rankB)
{
    int result;

    int weightA = getRankWeight(rankA);
    int weightB = getRankWeight(rankB);

    if (weightA > weightB)
    {
        result = 1;
    }

    else if (weightA == weightB)
    {
        result = 0;
    }

    else 
    {
        result = -1;
    }

    return result;
}

// Return suit weight (H > S > D > C)
int getSuitWeight(int suit)
{
    int weight;

    switch (suit)
    {
        case 'H':
            weight = 4;
            break;
        case 'S':
            weight = 3;
            break;
        case 'D':
            weight = 2;
            break;
        case 'C':
            weight = 1;
            break;
    }

    return weight;
}

// Return rank weight (2 ~ A)
int getRankWeight(char rank)
{
    int weight;

    if (rank >= '2' && rank <= '9')
    {
        weight = rank - '0';
    }

    else
    {
        switch (rank)
        {
            // Case for 10
            case '1':
                weight = 10;
                break;
            case 'J':
                weight = 11;
                break;
            case 'Q':
                weight = 12;
                break;
            case 'K':
                weight = 13;
                break;
            case 'A':
                weight = 14;
                break;
        }
    }

    return weight;
}

// Swap player's card i and card j
void swapCard(Player *player, int i, int j)
{
    // Swap suit
    char tmpSuit = player->suit[i];
    player->suit[i] = player->suit[j];
    player->suit[j] = tmpSuit;

    // Swap rank
    char tmpRank[3];
    strcpy(tmpRank, player->rank[i]);
    strcpy(player->rank[i], player->rank[j]);
    strcpy(player->rank[j], tmpRank);
}

