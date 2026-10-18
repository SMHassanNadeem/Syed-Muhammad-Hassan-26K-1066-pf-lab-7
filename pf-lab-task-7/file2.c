#include <stdio.h>
int main()
{
    int marks[6][4] = {0};
    int sum = 0;
    float average[4] = {0.0};
    float highestIndex = 0;

    for (int i = 0; i < 6; i++)
    {
        printf("Marks of Student%d \n", i);
        for (int j = 0; j < 4; j++)
        {
            printf("Marks of Subject %d :", j);
            scanf("%d", &marks[i][j]);
        }
    }

    for (int i = 0; i < 6; i++)
    {
        sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += marks[i][j];
        }
        printf("\n marks of student%d is %d \n", i, sum);
        printf("average marks of student%d is %d \n", i, sum / 4);
    }

    for (int i = 0; i < 4; i++)
    {
        sum = 0;
        for (int j = 0; j < 6; j++)
        {
            sum += marks[j][i];
        }
        average[i] = sum / 6;
    }

    float highests = average[0];
    for (int i = 0; i < 4; i++)
    {
        if(average[i] > highests){
            highests = average[i];
            highestIndex = i;
        }
    }

    printf("Name of Subject where class performed best: %f",highestIndex);
}