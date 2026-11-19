#include <stdio.h>
#include <stdlib.h>
struct Student
{
    int id;
    char name[50];
    char dept[50];
    float cgpa;
};
void addStudent()
{
    FILE *fp = fopen("students.dat", "ab");
    if (!fp)
        return;
    struct Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Department: ");
    scanf(" %[^\n]", s.dept);

    printf("Enter CGPA: ");
    scanf("%f", &s.cgpa);
    
    fwrite(&s, sizeof(struct Student), 1, fp);
    fclose(fp);
    printf("Record saved.\n");
}
void displayStudents()
{
    FILE *fp = fopen("students.dat", "rb");
    if (!fp)
    {
        printf("No records available.\n");
        return;
    }
    struct Student s;
    printf("\n--- Stored Student Records ---\n");
    while (fread(&s, sizeof(struct Student), 1, fp) == 1)
    {
        printf("ID: %d | Name: %s | Dept: %s | CGPA: %.2f\n", s.id, s.name, s.dept,
               s.cgpa);
    }
    fclose(fp);
}
void searchStudent()
{
    FILE *fp = fopen("students.dat", "rb");
    if (!fp)
        return;
    int id, found = 0;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    struct Student s;
    while (fread(&s, sizeof(struct Student), 1, fp) == 1)
    {
        if (s.id == id)
        {
            printf("Found -> ID: %d | Name: %s | Dept: %s | CGPA: %.2f\n", s.id, s.name,
                   s.dept, s.cgpa);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Student not found.\n");
    fclose(fp);
}
void updateCGPA()
{
    FILE *fp = fopen("students.dat", "rb+");
    if (!fp)
        return;
    int id, found = 0;
    printf("Enter ID to update CGPA: ");
    scanf("%d", &id);
    struct Student s;
    while (fread(&s, sizeof(struct Student), 1, fp) == 1)
    {
        if (s.id == id)
        {
            printf("Enter new CGPA: ");
            scanf("%f", &s.cgpa);
            fseek(fp, -(long)sizeof(struct Student), SEEK_CUR);
            fwrite(&s, sizeof(struct Student), 1, fp);
            printf("CGPA updated successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Student not found.\n");
    fclose(fp);
}
void deleteStudent()
{
    FILE *fp = fopen("students.dat", "rb");
    if (!fp)
        return;
    FILE *temp = fopen("temp.dat", "wb");
    if (!temp)
    {
        fclose(fp);
        return;
    }
    int id, found = 0;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    struct Student s;
    while (fread(&s, sizeof(struct Student), 1, fp) == 1)
    {
        if (s.id == id)
        {
            found = 1;
        }
        else
        {
            fwrite(&s, sizeof(struct Student), 1, temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("students.dat");
    rename("temp.dat", "students.dat");
    if (found)
        printf("Record deleted successfully.\n");
    else
        printf("Student ID not found.\n");
}
int main()
{
    int choice;
    while (1)
    {
 printf("\n1. Add Student\n2. Display All\n3. Search by ID\n4. UpdateCGPA\n5. Delete Record\n6. Exit\nChoice: ");
 scanf("%d", &choice);
 switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            updateCGPA();
            break;
        case 5:
            deleteStudent();
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice!\n");
 }
    }
}