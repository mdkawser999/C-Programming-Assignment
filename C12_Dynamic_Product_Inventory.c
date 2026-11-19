#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, choice, idx, extra;
    float *prices;
    printf("Enter initial number of products: ");
    scanf("%d", &n);

    prices = (float *)calloc(n, sizeof(float));
    if (prices == NULL)
        return 1;
    for (int i = 0; i < n; i++)
    {
        printf("Enter price for product %d: ", i + 1);
        scanf("%f", &prices[i]);
    }
    while (1)
    {
        printf("\n1. Update Price\n2. Add More Products\n3. Show Min/Max &Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter product number (1-%d): ", n);
            scanf("%d", &idx);
            if (idx >= 1 && idx <= n)
            {
                printf("Enter new price: ");
                scanf("%f", &prices[idx - 1]);
            }
        }
        else if (choice == 2)
        {
            printf("How many new products to add? ");
            scanf("%d", &extra);
            if (extra > 0)
            {
                float *temp = (float *)realloc(prices, (n + extra) *sizeof(float));
                if (temp == NULL)
                {
                    free(prices);
                    return 1;
                }
                prices = temp;
                for (int i = n; i < n + extra; i++)
                {
                    printf("Enter price for product %d: ", i + 1);
                    scanf("%f", &prices[i]);
                }
                n += extra;
            }
        }
        else if (choice == 3)
        {
            break;
        }
    }
    float max = prices[0], min = prices[0];
    for (int i = 1; i < n; i++)
    {
        if (prices[i] > max)
            max = prices[i];
        if (prices[i] < min)
            min = prices[i];
    }
    printf("\nMost Expensive Product Price: %.2f\n", max);
    printf("Least Expensive Product Price: %.2f", min);

    free(prices);
    return 0;
}