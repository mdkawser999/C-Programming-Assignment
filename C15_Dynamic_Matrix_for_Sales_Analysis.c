#include <stdio.h>
#include <stdlib.h>

int main()
{
    int branches, months, bestBranch = 0;
    float maxSales = -1;
    printf("Enter number of branches: ");
    scanf("%d", &branches);

    printf("Enter number of months: ");
    scanf("%d", &months);

    float **sales = (float **)malloc(branches * sizeof(float *));
    if (sales == NULL)
        return 1;
    for (int i = 0; i < branches; i++)
    {
        sales[i] = (float *)malloc(months * sizeof(float));
        if (sales[i] == NULL)
            return 1;
    }
    for (int i = 0; i < branches; i++)
    {
        printf("\nEnter sales for Branch %d:\n", i + 1);
        for (int j = 0; j < months; j++)
        {
            printf(" Month %d: ", j + 1);
            scanf("%f", &sales[i][j]);
        }
    }
    printf("\n--- Branch Total Sales ---\n");
    for (int i = 0; i < branches; i++)
    {
        float total = 0;
        for (int j = 0; j < months; j++)
        {
            total += sales[i][j];
        }
        printf("Branch %d Total Sales: %.2f\n", i + 1, total);
        if (total > maxSales)
        {
            maxSales = total;
            bestBranch = i + 1;
        }
    }
    printf("\nBranch with Highest Total Sales: Branch %d (%.2f)\n", bestBranch,maxSales);
    for (int i = 0; i < branches; i++)
    {
        free(sales[i]);
    }
    free(sales);
    return 0;
}
