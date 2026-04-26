#include <stdio.h>
#include <string.h>

int checkSame(char suitA, char suitB, char rankA[3], char rankB[3]);
int checkInput(char suitA[3], char rank[4][3]);
int checkSuitLegal(char a);
int checkRankLegal(char a[3]);
int calculateValue(char rank[3]);
void sortCard(char suit[4], char rank[4][3]);
int compare(char suitA, char suitB, char rankA[3], char rankB[3]);
int compareSuit(char suit1, char suit2);
int compareValue(char rankA[3], char rankB[3]);
int suitScore(char suit);
int getHandType(char suit[3], char rank[4][3]);
int isFlush(char suit[3]);
int isBomb(char rank[4][3]);
int isStraight(char rank[4][3]);
int hasPair(char rank[4][3]);
int compareHands(char suitA[3], char suitB[3], char rankA[4][3], char rankB[4][3]);

int main(void)
{
    // Player 1 input
    char suitA[4];
    char rankA[4][3];

    char suitB[4];
    char rankB[4][3];

    scanf(" %c%s %c%s %c%s", &suitA[0], rankA[0], &suitA[1], rankA[1], &suitA[2], rankA[2]);

    scanf(" %c%s %c%s %c%s", &suitB[0], rankB[0], &suitB[1], rankB[1], &suitB[2], rankB[2]);

    // Check Player's Input
    for (int i = 0; i < 2; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            int checkSameResultA = checkSame(suitA[i], suitA[j], rankA[i], rankA[j]);
            int checkSameResultB = checkSame(suitB[i], suitB[j], rankB[i], rankB[j]);
            if ((checkSameResultA == 1) || (checkSameResultB == 1))
            {
                printf("Input Error!\n");
                return 1;
            }
        }
    }
    
    int checkInputA = checkInput(suitA, rankA);
    int checkInputB = checkInput(suitB, rankB);

    if ((checkInputA != 1) || (checkInputB != 1))
    {
        printf("Input Error!\n");
        return 2;
    }

    // Sort Player 1
    sortCard(suitA, rankA);

    // Sort Player 2
    sortCard(suitB, rankB);

    int result = compareHands(suitA, suitB, rankA, rankB);

    if (result == 1)
    {
        printf("Winner is A!\n");
    }

    else if (result == 0)
    {
        printf("Winner is B!\n");
    }
    
    else 
    {
        printf("Draw!\n");
    }

    printf("A: %c%s %c%s %c%s\n", suitA[0], rankA[0], suitA[1], rankA[1], suitA[2], rankA[2]);
    printf("B: %c%s %c%s %c%s\n", suitB[0], rankB[0], suitB[1], rankB[1], suitB[2], rankB[2]);

    return 0;
}

int checkSame(char suitA, char suitB, char rankA[3], char rankB[3])
{
    return ((suitA == suitB) && (strcmp(rankA, rankB) == 0));
}

// Return 1 if input is legal
int checkInput(char suit[3], char rank[4][3])
{
    int suitIsLegal = 0; 
    int rankIsLegal = 0;
    // Check suit legal
    for (int i = 0; i < 3; i++)
    {
        suitIsLegal += checkSuitLegal(suit[i]);
        rankIsLegal += checkRankLegal(rank[i]);
    }

    if ((suitIsLegal == 3) && (rankIsLegal == 3))
    {
        return 1;
    }

    return 0;
}


// Return 1 if suit is legal
int checkSuitLegal(char a)
{
    char suit[4] = {'H', 'S', 'D', 'C'};
    for (int i = 0; i < 4; i++)
    {
        if (a == suit[i])
        {
            return 1;
        }
    }
    return 0;
}

// Return 1 if rank is legal
int checkRankLegal(char a[3])
{
    char rank[13][3] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    for (int i = 0; i < 13; i++)
    {
        if (strcmp(a, rank[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}


int calculateValue(char rank[3])
{
    int value;
    // Case for 10
    if (rank[0] == '1' && rank[1] == '0')
    {
        value = 10;
        return value;
    }

    value = rank[0] - '0';
    switch (rank[0])
    {
        case 'A':
            value = 14;
            break;
        case 'K':
            value = 13;
            break;
        case 'Q':
            value = 12;
            break;
        case 'J':
            value = 11;
            break;
    }

    return value;
}

// Sort card by its value
void sortCard(char suit[4], char rank[4][3])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (compare(suit[i], suit[j], rank[i], rank[j]) < 0)
            {
                char tmpSuit;
                tmpSuit = suit[j];
                suit[j] = suit[i];
                suit[i] = tmpSuit;

                char tmpRank[3];
                strcpy(tmpRank, rank[j]);
                strcpy(rank[j], rank[i]);
                strcpy(rank[i], tmpRank);
            }
        }
    }
}

// Return 1 if greater, 0 if equal, -1 if less than
int compare(char suitA, char suitB, char rankA[3], char rankB[3])
{
    int suitCompareResult = compareSuit(suitA, suitB);
    int valueCompareResult = compareValue(rankA, rankB);
    if (valueCompareResult > 0)
    {
        return 1;
    }
    else
    {
        if (valueCompareResult == 0)
        {
            if (suitCompareResult > 0)
            {
                return 1;
            }

            else if (suitCompareResult == 0)
            {
                return 0;
            }

            else
            {
                return -1;
            }
        }

        else 
        {
            return -1;
        }
    }
}

// Return positive number when greater, return 0 when equal, negative when less than
int compareSuit(char suit1, char suit2)
{
    return (suitScore(suit1) - suitScore(suit2));
}

// Return positive number when greater, return 0 when equal, negative when less than
int compareValue(char rankA[3], char rankB[3])
{
    int valueA = calculateValue(rankA);
    int valueB = calculateValue(rankB);
    
    return (valueA - valueB);
}

// Suit Score
int suitScore(char suit)
{
    int score;
    switch (suit)
    {
    case 'H':
        score = 4;
        break;
    case 'S':
        score = 3;
        break;
    case 'D':
        score = 2;
        break;
    case 'C':
        score = 1;
        break;
    }
    return score;
}

int getHandType(char suit[3], char rank[4][3])
{
    // Same suit
    int flush = isFlush(suit);

    // Same rank
    int bomb = isBomb(rank);

    // Straight rank
    int straight = isStraight(rank);

    // Two same suit
    int pair = hasPair(rank);

    if (flush && straight)
    {
        return 5;
    }

    if (bomb)
    {
        return 4;
    }

    if (straight)
    {
        return 3;
    }

    if (pair)
    {
        return 2;
    }

    return 1;
}

// Return 1 if A wins, return 0 if B wins, return -1 if draw
int compareHands(char suitA[3], char suitB[3], char rankA[4][3], char rankB[4][3])
{
    int handA  = getHandType(suitA, rankA);
    int handB = getHandType(suitB, rankB);

    // If handA != handB
    if (handA != handB)
    {
        return (handA > handB);
    }

    // If handA = handB then compare rank then compare 
    else 
    {
        int i = 0;
        int j = 0; 
        while ((i != 3) || (j != 3))
        {
            int result = compare(suitA[i], suitB[j], rankA[i], rankB[j]); 
            if (result == 1)
            {
                return 1;
            }

            else if (result == -1)
            {
                return 0;
            }

            else 
            {
                i += 1;
                j += 1;
            }      
        }

        return -1;
    }
}

// Return 1 if all suit are same, else return 0
int isFlush(char suit[3])
{
    return ((suit[0] == suit[1]) && (suit[1] == suit[2]));
}

// Return 1 if three rank are same else return 0
int isBomb(char rank[4][3])
{
    if ((strcmp(rank[0], rank[1]) == 0) && (strcmp(rank[1], rank[2]) == 0))
    {
        return 1;
    }

    return 0;
}

// Return 1 if is Straight else return 0
int isStraight(char rank[4][3])
{
    int value1 = calculateValue(rank[0]);
    int value2 = calculateValue(rank[1]);
    int value3 = calculateValue(rank[2]);

    return ((value2 == (value1 - 1)) && (value3 == (value2 - 1)));
}

// Return 1 if two of the rank are same
int hasPair(char rank[4][3])
{
    return ((strcmp(rank[0], rank[1]) == 0) || (strcmp(rank[1], rank[2]) == 0) || (strcmp(rank[0], rank[2]) == 0));
}
