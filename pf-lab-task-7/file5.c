#include <stdio.h>
int main()
{
    int hotel[4][6] = {0};
    int sum = 0;
    int highestVacant = 0;
    int threeOrMoreVacantCount = 0;

    int vacantArr[4] = {0};
    int vacantCount = 0;

    for (int i = 0; i < 4; i++)
    {
        printf("Enter occupancy status of Floor%d \n", i);
        for (int j = 0; j < 6; j++)
        {
            printf("Room%d (1-Occupied / 0-Vacant) :", j);
            scanf("%d", &hotel[i][j]);
        }
    }

    int highestCountArr[4] = {0};
    int visited[6] = {0};

    for (int i = 0; i < 4; i++)
    {
        vacantCount = 0;
        for (int j = 0; j < 6; j++)
        {
            if (hotel[i][j] == 0)
            {
                vacantCount++;
            }
        }
        highestCountArr[i] = vacantCount;
    }

    int highest = highestCountArr[0];
    int highestCount = 0;
    for (int i = 0; i < 4; i++)
    {
        if (highestCountArr[i] > highest)
        {
            highest = highestCountArr[i];
            highestCount = i;
        }
    }

    printf("Hotel Vacancy Report\n");
    for (int i = 0; i < 4; i++)
    {
        printf("Floor %d has %d vacant rooms.\n", i, highestCountArr[i]);
    }

    int foundAnyConsecutive = 0;
    for (int i = 0; i < 4; i++)
    {
        int consecutiveCount = 0;
        int startRoom = -1;
        int triggeredOnFloor = 0;

        for (int j = 0; j < 6; j++)
        {
            if (hotel[i][j] == 0)
            {
                if (consecutiveCount == 0)
                {
                    startRoom = j;
                }
                consecutiveCount++;

                if (consecutiveCount >= 3 && !triggeredOnFloor)
                {
                    printf("Floor %d has 3 or more consecutive vacant rooms starting at Room %d.\n", i, startRoom);
                    triggeredOnFloor = 1;
                    foundAnyConsecutive = 1;
                }
            }
            else
            {
                consecutiveCount = 0;
            }
        }
    }

    if (!foundAnyConsecutive)
    {
        printf("No floors have 3 or more consecutive vacant rooms.\n");
    }
}