#include <stdio.h>

int main()
{
    FILE *fp;
    int choice, tID, cID, qty, searchCID;
    float price, totalSales;
    while (1)
    {
        printf("\n1. Add Transaction\n2. View All & Total Sales\n3. Search byCustomer ID\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            fp = fopen("transactions.txt", "a");
            if (fp == NULL)
                continue;
            printf("Transaction ID: ");
            scanf("%d", &tID);

            printf("Customer ID: ");
            scanf("%d", &cID);

            printf("Product Price: ");
            scanf("%f", &price);

            printf("Quantity: ");
            scanf("%d", &qty);
            
            fprintf(fp, "%d %d %.2f %d\n", tID, cID, price, qty);
            fclose(fp);
            printf("Transaction saved.\n");
        }
        else if (choice == 2)
        {
            fp = fopen("transactions.txt", "r");
            if (fp == NULL)
            {
                printf("No transactions found.\n");
                continue;
            }
            totalSales = 0.0f;
            printf("\n--- Transaction History ---\n");
            while (fscanf(fp, "%d %d %f %d", &tID, &cID, &price, &qty) == 4)
            {
                float amount = price * qty;
                totalSales += amount;
                printf("Trans ID: %d | Cust ID: %d | Price: %.2f | Qty: %d | Subtotal: %.2f\n",
                       tID, cID, price, qty, amount);
            }
            printf("Total Sales Amount: %.2f\n", totalSales);
            fclose(fp);
        }
        else if (choice == 3)
        {
            fp = fopen("transactions.txt", "r");
            if (fp == NULL)
                continue;
            printf("Enter Customer ID: ");
            scanf("%d", &searchCID);
            int found = 0;
            while (fscanf(fp, "%d %d %f %d", &tID, &cID, &price, &qty) == 4)
            {
                if (cID == searchCID)
                {
                    printf("Trans ID: %d | Price: %.2f | Qty: %d | Total: %.2f\n",
                           tID, price, qty, price * qty);
                    found = 1;
                }
            }
            if (!found)
                printf("No transactions found for Customer ID %d.\n",
                       searchCID);
            fclose(fp);
        }
        else if (choice == 4)
        {
            break;
        }
    }
    return 0;
}