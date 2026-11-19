#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, choice, seatNum;
    printf("Enter total number of seats: ");
    scanf("%d", &n);

    int *seats = (int *)calloc(n, sizeof(int)); // 0 = available, 1 = booked
    if (seats == NULL)
        return 1;
    while (1)
    {
        int booked = 0, available = 0;
        for (int i = 0; i < n; i++)
        {
            if (seats[i] == 1)
                booked++;
            else
                available++;
        }
        printf("\nTotal Booked: %d | Total Available: %d\n", booked, available);
        printf("1. Book Seat\n2. Cancel Seat\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 3)
            break;
        printf("Enter seat number (1-%d): ", n);
        scanf("%d", &seatNum);

        if (seatNum < 1 || seatNum > n)
        {
            printf("Invalid seat number!\n");
            continue;
        }
        if (choice == 1)
        {
            if (seats[seatNum - 1] == 0)
            {
                seats[seatNum - 1] = 1;
                printf("Seat %d booked successfully.\n", seatNum);
            }
            else
            {
                printf("Seat %d is already booked!\n", seatNum);
            }
        }
        else if (choice == 2)
        {
            if (seats[seatNum - 1] == 1)
            {
                seats[seatNum - 1] = 0;
                printf("Seat %d booking cancelled.\n", seatNum);
            }
            else
            {
                printf("Seat %d is not currently booked.\n", seatNum);
            }
        }
    }
    free(seats);
    return 0;
}
