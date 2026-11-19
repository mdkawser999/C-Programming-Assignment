#include <stdio.h>

void updateBalance(float *balance, float amount, int choice)
{
    if (amount <= 0)
    {
        printf("Invalid amount!\\n");
    }
    else if (choice == 1)
    {
        *balance += amount;
    }
    else if (choice == 2)
    {
        if (amount <= *balance)
            *balance -= amount;
        else
            printf("Insufficient balance!\\n");
    }
    else
    {
        printf("Invalid choice!\\n");
    }
}
int main()
{
    float balance, amount;
    int choice;

    printf("Enter initial balance: ");
    scanf("%f", &balance);

    printf("1. Deposit 2. Withdraw\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter amount: ");
    scanf("%f", &amount);

    updateBalance(&balance, amount, choice);
    printf("Updated balance = %.2f\n", balance);
    return 0;
}