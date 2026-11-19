#include <stdio.h>

int main()
{
    FILE *fp;
    int id;
    char name[50];
    float marks, sum = 0.0f;
    int count = 0;
    fp = fopen("results.txt", "w");
    if (fp == NULL)
    {
        printf("Error: Could not open results.txt for writing!\n");
        return 1;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &id);

        printf("Name (single word or underscore): ");
        scanf("%49s", name);

        printf("Marks: ");
        scanf("%f", &marks);
        
        fprintf(fp, "%d %s %.2f\n", id, name, marks);
    }
    fclose(fp);
    fp = fopen("results.txt", "r");
    if (fp == NULL)
    {
        printf("Error: Could not open results.txt for reading!\n");
        return 1;
    }
    printf("\n--- Stored Student Records ---\n");
    while (fscanf(fp, "%d %49s %f", &id, name, &marks) == 3)
    {
        printf("ID: %d | Name: %s | Marks: %.2f\n", id, name, marks);
        sum += marks;
        count++;
    }
    fclose(fp);
    if (count > 0)
    {
        printf("\nAverage Marks: %.2f\n", sum / count);
    }
    return 0;
}
