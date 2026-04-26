#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int id;
    int cardCount;
    char *suit;
    char (*rank)[3];
    int score;
} Player;

int checkOneHasAllHeart(int playerCount, Player players[4]);
int hasAllHeart(Player player);
int calculateScore(Player player, int oneHasAllHeart);
int calculateCardWeight(char suit, char firstNum, char secondNum);
int calculateValue(char firstNum, char secondNum);

int main(void)
{

    Player players[50];

    int playerIndex = 0;

    // Read player info and create player
    while (1)
    {
        int isLast = 0;

        for (int i = 0; i < 4; i++)
        {
            int cardCount;
            scanf("%d", &cardCount);

            players[playerIndex].id = playerIndex; 
            players[playerIndex].score = 0;
            players[playerIndex].cardCount = cardCount;

            if (cardCount == 0)
            {
                isLast++;
                players[playerIndex].suit = NULL;
                players[playerIndex].rank = NULL;
            }

            else
            {
                char *suit = (char*)malloc(cardCount * sizeof(char));
                char (*rank)[3] = (char(*)[3])malloc(cardCount * sizeof(char[3]));
                for (int j = 0; j < cardCount; j++)
                {
                    scanf(" %c%2s", &suit[j], rank[j]);
                }
                players[playerIndex].suit = suit;
                players[playerIndex].rank = rank;
            } 

            playerIndex++;
        }

        if (isLast == 4)
        {
            break;
        }
    }

    int playerCount = playerIndex - 4;
    int gameCount = (playerCount / 4);

    // Calculate score
    for (int i = 0; i < gameCount; i++)
    {
        Player game_player[4] = {players[0 + (4 * i)], players[1 + (4 * i)], players[2 + (4 * i)], players[3 + (4 * i)]};
        int oneHasAllHeart = checkOneHasAllHeart(4, game_player);
        for (int j = 0; j < 4; j++)
        {
            players[j + (4 * i)].score = calculateScore(players[j + (4 * i)], oneHasAllHeart);
        }
    }

    // If one of the player's score is 1000 then other player's score is 0
    for (int i = 0; i < gameCount; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int currentScore = players[j + (4 * i)].score;

            if (currentScore == 1000)
            {
                int index = j + 4 * i;

                for (int k = 0; k < 4; k++)
                {
                    if (k == index)
                    {
                        continue;
                    }
                    else
                    {
                        players[k + (4 * i)].score = 0;
                    }
                }
            }
        }
    }

    for (int i = 0; i < gameCount; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int currentScore = players[j + (4 * i)].score;
            if (currentScore > 0)
            {
                if (j == 3)
                {
                    printf("+%d", currentScore);
                }
                else
                {
                    printf("+%d ", currentScore);
                }
            }
            else
            {
                if (j == 3)
                {
                    printf("%d", currentScore);
                }
                else
                {
                    printf("%d ", currentScore);
                }
            }
        }
        printf("\n");
    }

    for(int k = 0; k < playerCount; k++)
    {
        if(players[k].suit != NULL) free(players[k].suit);
        if(players[k].rank != NULL) free(players[k].rank);
    }

}

// Return 1 if one of the player have all Heart
int checkOneHasAllHeart(int playerCount, Player players[4])
{
    int hasAllHeartCount = 0;

    for (int i = 0; i < playerCount; i++)
    {
        if (hasAllHeartCount >= 2)
        {
            return 0;
        }

        if (hasAllHeart(players[i]) == 1)
        {
            hasAllHeartCount++;
        }
    }

    return hasAllHeartCount;
}

// Return 1 if player have all Heart
int hasAllHeart(Player player)
{
    if (player.suit == NULL)
    {
        return 0;
    }

    int cardCount = player.cardCount;

    if (cardCount < 13)
    {
        return 0;
    }
    
    for (int i = 0; i < cardCount; i++)
    {
        if (player.suit[i] != 'H')
        {
            return 0;
        }
    }   
    
    return 1;
}

// Return score of player 
int calculateScore(Player player, int oneHasAllHeart)
{
    int cardCount = player.cardCount;
    int validCount = 0;

    int hasC10 = 0;
    int hasD11 = 0;
    int hasS12 = 0;

    int score = 0;

    // Find out valid card and process 'H' Card
    for (int i = 0; i < cardCount; i++)
    {        
        int cardWeight = calculateCardWeight(player.suit[i], player.rank[i][0], player.rank[i][1]);
        // If card is not valid then just skip (Valid card: S12, All H, D11, C10)
        if (cardWeight == 0) 
        {
            continue;
        }

        validCount++;
        if (cardWeight == 10)
        {
            hasC10 = 1;
        }

        else if (cardWeight == 11)
        {
            hasD11 = 1;
        }

        else if (cardWeight == 12)
        {
            hasS12 = 1;
        }

        /** If oneHasAllHeart != 1 
         * H1 ~ H13 = {-50，-2，-3，-4，-5，-6，-7，-8，-9，-10，-20，-30，-40}
         * S12 = -100
         * D11 = 100
        */
       else if (cardWeight >= 21 && cardWeight <= 33)
       {
            if (oneHasAllHeart != 1)
            {
                int heartScores[13] = {-50, -2, -3, -4, -5, -6, -7, -8, -9, -10, -20, -30, -40};
                // To know which card is 
                int index = cardWeight - 21;
                score += heartScores[index];
            }
       }
    }
     /** If player got all heart
         * score += 200
         * If has S12 && D11 then score += 500
         * C10 stay same
        */
       if (hasAllHeart(player) == 1)
       {
            score += 200;
            if (hasS12 == 1 && hasD11 == 1)
            {
                score += 500;
            }
       }

        // If have C10 but dont have other valid card then +50, else double the score
        if (hasC10 == 1 && (validCount - 1) == 0)
        {
            score += 50;
        }
        // If valid card = 16 then score += 1000, other player score == 0
        if (validCount == 16)
        {
            return 1000;
        }
        // If dont have valid card then return 0

        if (validCount == 0)
        {
            return 0;
        }

        if (hasAllHeart(player) != 1)
        {
            if (hasS12 == 1)
            {
                score -= 100;
            }

            if (hasD11)
            {
                score += 100;
            }
        }

        // If hasC10 then double the score
        if (hasC10 == 1)
        {
            score *= 2;
        }
    return score;
    
}

/**
 * Return 1 if suit is H
 * Return 10 if card is C10
 * Return 11 if card is D11
 * Return 12 if card is S12
 * else return 0 (Not Valid)
 */
int calculateCardWeight(char suit, char firstNum, char secondNum)
{
    // All H (return 21 ~ 33)
    if (suit == 'H')
    {
        int n = calculateValue(firstNum, secondNum);
        return 20 + n;
    }

    // S12
    else if (suit == 'S' && firstNum== '1' && secondNum == '2')
    {
        return 12;
    }

    // D11
    else if (suit == 'D' && firstNum== '1' && secondNum == '1')
    {
        return 11;
    }

    // C10
    else if (suit == 'C' && firstNum== '1' && secondNum == '0')
    {
        return 10;
    }

    return 0;
}

int calculateValue(char firstNum, char secondNum)
{
    int value;
    // Case for 10 ~ 13
    if (firstNum == '1' && secondNum == '0')
    {
        value = 10;
    }

    else if (firstNum == '1' && secondNum == '1')
    {
        value = 11;
    }

    else if (firstNum == '1' && secondNum == '2')
    {
        value = 12;
    }

    else if (firstNum == '1' && secondNum == '3')
    {
        value = 13;
    }

    else
    {
        value = firstNum - '0';
    }

    return value;
}
