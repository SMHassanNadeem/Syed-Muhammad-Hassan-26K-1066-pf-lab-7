#include <stdio.h>
int main()
{
    int sales[3][5] = {0};
    int sum = 0;
    int bestSellingBranch = 0;
    int lowestSellingProduct = 0;

    int branchArr[3] = {0};
    int productArr[5] = {0};

    for (int i = 0; i < 3; i++)
    {
        printf("Sales of Branch%d \n", i);
        for (int j = 0; j < 5; j++)
        {
            printf("Product%d :", j);
            scanf("%d", &sales[i][j]);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum += sales[i][j];
        }
        printf("\n Sales of Branch%d is %d \n", i, sum);
        branchArr[i] = sum;
    }

    for (int i = 0; i < 5; i++)
    {
        sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += sales[j][i];
        }
        printf("\n Sales of Product%d is %d \n", i, sum);
        productArr[i] = sum;
    }

    int lowestProduct = productArr[0];
    int lowestProductName = 0;
    for (int i = 0; i < 5; i++)
    {
        if(productArr[i] < lowestProduct){
            lowestProduct = productArr[i];
            lowestProductName = i;
        }
    }

    int bestBranch = branchArr[0];
    int bestBranchName = 0;
    for (int i = 0; i < 3; i++)
    {
        if(branchArr[i] > bestBranch){
            bestBranch = branchArr[i];
            bestBranchName = i;
        }
    }
    
    printf("\nName of Best Selling Branch: Branch%d \n Name of Lowest Selling Product: Product%d",bestBranchName,lowestProductName);
}