#include <stdio.h>

int isLargestInRow(int row, int col, int x1, int y1, int num, int matrix[row][col]);
int findLargestInRow(int row, int col, int x1, int y1, int matrix[row][col]);
int isSmallestInCol(int row, int col, int x1, int y1, int num, int matrix[row][col]);
int findSmallestInCol(int row, int col, int x1, int y1, int matrix[row][col]);

int main(void)
{
    int row, col;

    scanf("%d %d", &row, &col);

    int matrix[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int hasSaddle = 0;
    int saddlePointY;
    int saddlePointX;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int current_num = matrix[i][j];
            if (isLargestInRow(row, col, j, i, current_num, matrix) == 1 && isSmallestInCol(row, col, j, i, current_num, matrix) == 1)
            {
                hasSaddle = 1;
                saddlePointY = i;
                saddlePointX = j;
            }
        }
    }
    
    if (hasSaddle == 1)
    {
        printf("Point:a[%d][%d]==%d\n", saddlePointY, saddlePointX, matrix[saddlePointY][saddlePointX]);
    }

    else 
    {
        printf("No Point\n");
    }

    return 0;

}

// Return 1 if current num is largest in its row
int isLargestInRow(int row, int col, int x1, int y1, int num, int matrix[row][col])
{
    int largest = findLargestInRow(row, col, x1, y1, matrix);

    if (num == largest)
    {
        return 1;
    }

    return 0;
}

int findLargestInRow(int row, int col, int x1, int y1, int matrix[row][col])
{
    int start_point = 0;
    int largest = matrix[y1][start_point];

    while (start_point < col - 1)
    {
        start_point += 1;
        int current = matrix[y1][start_point];
        if (current > largest)
        {
            largest = current;
        }
    }

    return largest;
}


// Return 1 if current num is smallest in col
int isSmallestInCol(int row, int col, int x1, int y1, int num, int matrix[row][col])
{
    int smallest = findSmallestInCol(row, col, x1, y1, matrix);

    if (num == smallest)
    {
        return 1; 
    }

    return 0;
}

int findSmallestInCol(int row, int col, int x1, int y1, int matrix[row][col])
{
    int start_point = 0;
    int smallest = matrix[start_point][x1];

    while (start_point < row - 1)
    {
        start_point += 1;
        int current = matrix[start_point][x1];
        if (current < smallest)
        {
            smallest = current;
        }
    }

    return smallest;
}
