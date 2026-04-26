#include <stdio.h>

void answerProcess(int row, int col, char map[row][col], char result[row][col]);
char mineCount(int row, int col, int x1, int y1, char map[row][col]);

int main(void)
{
    int field_count = 1;
    while (1)
    {
        int row, col;
        scanf("%d %d", &row, &col);

        if (row == 0 && col == 0)
        {
            break;
        }

        char map[row][col];
        for (int i = 0; i < row; i++)
        {
            scanf("%s", map[i]);
        }

        char result[row][col];
        
        answerProcess(row, col, map, result);

        printf("Field #%d:\n", field_count);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                printf("%c", result[i][j]);
            }

            printf("\n");
        }
        field_count += 1;
    }

    return 0;
}

void answerProcess(int row, int col, char map[row][col], char result[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = mineCount(row, col, i, j, map);
        }
    }
}


char mineCount(int row, int col, int x1, int y1, char map[row][col])
{
    // Return * if map[i][j] is mine
    if (map[x1][y1] == '*')
    {
        return '*';
    }

    int counter = 0;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int neighbor_x = x1 + i;
            int neighbor_y = y1 + j;

            // Check if not out of map
            if ((neighbor_x > -1) && !(neighbor_x >= col) && (neighbor_y > - 1) && !(neighbor_y >= row))
            {
                if (map[neighbor_x][neighbor_y] == '*')
                {
                    counter += 1;
                }
            }
        }
    }

    return counter + '0';
}