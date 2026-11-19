#include <stdio.h>
#include <stdlib.h>

struct Employee{
    int id;
    char name[50];
    float salary;
};
int main()
{
    int n, choice, searchID;
    printf("Enter initial number of employees: ");
    scanf("%d", &n);

    struct Employee *emp = (struct Employee *)malloc(n *sizeof(struct Employee));
    if (emp == NULL)
        return 1;
    for (int i = 0; i < n; i++){
        printf("\nEmployee %d ID: ", i + 1);
        scanf("%d", &emp[i].id);

        printf("Name: ");
        scanf(" %[^\n]", emp[i].name);

        printf("Salary (BDT): ");
        scanf("%f", &emp[i].salary);
    }
    while (1){
        printf("\n1. Add New Employee\n2. Search by ID\n3. Display Salary > 50,000BDT\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1){
            struct Employee *temp = (struct Employee *)realloc(emp, (n + 1) *sizeof(struct Employee));
            if (temp == NULL)
                break;
            emp = temp;
            printf("Enter ID: ");
            scanf("%d", &emp[n].id);

            printf("Enter Name: ");
            scanf(" %[^\n]", emp[n].name);

            printf("Enter Salary: ");
            scanf("%f", &emp[n].salary);
            n++;
        }
        else if (choice == 2){
            printf("Enter ID to search: ");
            scanf("%d", &searchID);

            int found = 0;
            for (int i = 0; i < n; i++)
            {
                if (emp[i].id == searchID)
                {
                    printf("Found: %s | Salary: %.2f BDT\n", emp[i].name,
                           emp[i].salary);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Employee not found.\n");
        }
        else if (choice == 3){
            printf("\n--- Employees Earning > 50,000 BDT ---\n");
            for (int i = 0; i < n; i++)
            {
                if (emp[i].salary > 50000.0f)
                {
                    printf("ID: %d | Name: %s | Salary: %.2f BDT\n", emp[i].id, emp[i].name,
                           emp[i].salary);
                }
            }
        }
        else if (choice == 4){
            break;
        }
    }
    free(emp);
    return 0;
}