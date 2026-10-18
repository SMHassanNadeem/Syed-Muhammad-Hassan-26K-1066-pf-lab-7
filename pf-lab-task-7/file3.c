#include <stdio.h>
#include <string.h>

int main()
{
    int temp[7][4] = {0};

    for (int i = 0; i < 7; i++)
    {
        printf("Day %d", i);
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &temp[i][j]);
        }
    }

    int hottest = temp[0][0];
    int coldest = temp[0][0];
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (hottest > temp[i][j])
            {
                hottest = temp[i][j];
            }
            if (coldest < temp[i][j])
            {
                coldest = temp[i][j];
            }
        }
    }
    printf("Hottest Temperature: %d \n",hottest);
    printf("Coldest Temperature: %d \n",coldest);

    float sum = 0;
    for (int i = 0; i < 7; i++)
    {
        sum += temp[i][1];
    }
    // printf("noon average: %f", sum / 7.0);


    for (int i = 0; i < 7; i++)
    {
        if (temp[i][1] > (sum / 7.0))
        {
            printf("Day where noon temperature is above Average: %d\n", i);
        }
    }
}