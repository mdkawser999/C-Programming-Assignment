#include <stdio.h>
typedef struct Student{
    int id;
    char name[50];
    char department[50];
    float cgpa;
} Student;
int main()
{
    Student s[10];
    int maxIdx = 0, searchID, found = 0;
    printf("Enter information for 10 students:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("\nStudent %d ID: ", i + 1);
        scanf("%d", &s[i].id);
        printf("Name: ");
        scanf(" %[^\n]", s[i].name);
        printf("Department: ");
        scanf(" %[^\n]", s[i].department);
        printf("CGPA: ");
        scanf("%f", &s[i].cgpa);
        if (s[i].cgpa > s[maxIdx].cgpa)
        {
            maxIdx = i;
        }
    }
    printf("\n--- Student with Highest CGPA ---\n");
    printf("ID: %d | Name: %s | Dept: %s | CGPA: %.2f\n",
           s[maxIdx].id, s[maxIdx].name, s[maxIdx].department, s[maxIdx].cgpa);
    printf("\nEnter Student ID to search: ");
    scanf("%d", &searchID);
    for (int i = 0; i < 10; i++)
    {
        if (s[i].id == searchID)
        {
            printf("Record Found -> ID: %d | Name: %s | Dept: %s | CGPA: %.2f\n",
                   s[i].id, s[i].name, s[i].department, s[i].cgpa);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Student with ID %d not found.\n", searchID);
    return 0;
}