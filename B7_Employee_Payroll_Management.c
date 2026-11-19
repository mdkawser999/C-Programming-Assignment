#include <stdio.h>

typedef struct Employee{
    int id;
    char name[50];
    float basic, hra, medical, total;
} Employee;
int main()
{
    Employee emp[5];
    int maxIdx = 0;
    for (int i = 0; i < 3; i++)
    {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);

        printf("Name: ");
        scanf(" %[^\n]", emp[i].name);

        printf("Basic Salary: ");
        scanf("%f", &emp[i].basic);

        emp[i].hra = 0.40f * emp[i].basic;
        emp[i].medical = 0.10f * emp[i].basic;
        emp[i].total = emp[i].basic + emp[i].hra + emp[i].medical;
        if (emp[i].total > emp[maxIdx].total)
        {
            maxIdx = i;
        }
    }
    printf("\n--- Highest-Paid Employee ---\n");
    printf("ID: %d\nName: %s\nBasic: %.2f\nHRA: %.2f\nMedical: %.2f\nTotal Salary: %.2f\n ",
           emp[maxIdx].id,
           emp[maxIdx].name, emp[maxIdx].basic,
           emp[maxIdx].hra, emp[maxIdx].medical, emp[maxIdx].total);
    return 0;
}