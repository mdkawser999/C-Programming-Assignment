#include <stdio.h>

int main()
{
    FILE *fp;
    int choice, sID, bID, searchID, count;
    char date[20];
    while (1)
    {
        printf("\n1. Add Borrowing Record\n2. Display All & Count\n3. Search byStudent ID\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            fp = fopen("borrowed_books.txt", "a");
            if (fp == NULL)
            {
                printf("Error opening file!\n");
                continue;
            }
            printf("Enter Student ID: ");
            scanf("%d", &sID);

            printf("Enter Book ID: ");
            scanf("%d", &bID);

            printf("Enter Date (DD-MM-YYYY): ");
            scanf("%19s", date);
            
            fprintf(fp, "%d %d %s\n", sID, bID, date);
            fclose(fp);
            printf("Record added successfully.\n");
        }
        else if (choice == 2)
        {
            fp = fopen("borrowed_books.txt", "r");
            if (fp == NULL)
            {
                printf("No records found.\n");
                continue;
            }
            count = 0;
            printf("\n--- All Borrowing Records ---\n");
            while (fscanf(fp, "%d %d %19s", &sID, &bID, date) == 3)
            {
                printf("Student ID: %d | Book ID: %d | Date: %s\n", sID, bID, date);
                count++;
            }
            printf("Total Borrowing Records: %d\n", count);
            fclose(fp);
        }
        else if (choice == 3)
        {
            fp = fopen("borrowed_books.txt", "r");
            if (fp == NULL)
            {
                printf("No records found.\n");
                continue;
            }
            printf("Enter Student ID to search: ");
            scanf("%d", &searchID);
            int found = 0;
            while (fscanf(fp, "%d %d %19s", &sID, &bID, date) == 3)
            {
                if (sID == searchID)
                {
                    printf("Book ID: %d | Date: %s\n", bID, date);
                    found = 1;
                }
            }
            if (!found)
                printf("No borrowing records for Student ID %d.\n", searchID);
            fclose(fp);
        }
        else if (choice == 4)
        {
            break;
        }
    }
    return 0;
}