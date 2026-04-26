#include <stdio.h>
#include <stdlib.h>

float getMaxArea(int pointArray[][2], int point_count);

int main(void)
{
    int testCount;
    scanf("%d", &testCount);

    float ans[testCount];
    for (int i = 0; i < testCount; i++)
    {
        int point_count;
        scanf("%d", &point_count);

        int pointArray[point_count][2];

        for (int j = 0; j < point_count; j++)
        {
            scanf("%d %d", &pointArray[j][0], &pointArray[j][1]);
        }

        float maxArea = getMaxArea(pointArray, point_count);
        ans[i] = maxArea;
    }

    for (int i = 0; i < testCount; i++)
    {
        printf("%.2f\n", ans[i]);
    }
}

float getMaxArea(int pointArray[][2], int point_count)
{
    float result = 0;

    for (int i = 0; i < point_count; i++)
    {
        for (int j = i + 1; j < point_count; j++)
        {
            for (int k = j + 1; k < point_count; k++)
            {
                int x1 = pointArray[i][0];
                int y1 = pointArray[i][1];
                int x2 = pointArray[j][0];
                int y2 = pointArray[j][1];
                int x3 = pointArray[k][0];
                int y3 = pointArray[k][1];

                float area = (float) 0.5 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

                if (area < 0.0)
                {
                    area = -area;
                }

                if (area > result)
                {
                    result = area;
                }
            }
        }
    }

    return result;
}   