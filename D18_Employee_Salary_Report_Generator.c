#include <stdio.h>
int main()
{
    FILE *inFile, *outFile;
    int id;
    char name[50];
    float basic, bonus, updated, totalExpenditure = 0;
    inFile = fopen("employees.txt", "r");
    if (inFile == NULL)
    {
        printf("Error: Cannot open employees.txt! Ensure the file exists.\n");
        return 1;
    }
    outFile = fopen("salary_report.txt", "w");
    if (outFile == NULL)
    {
        printf("Error: Cannot create salary_report.txt!\n");
        fclose(inFile);
        return 1;
    }
    fprintf(outFile, "ID\tName\tBasic\tBonus\tUpdated_Salary\n");
    while (fscanf(inFile, "%d %49s %f", &id, name, &basic) == 3)
    {
        bonus = 0.10f * basic;
        updated = basic + bonus;
        totalExpenditure += updated;
        fprintf(outFile, "%d\t%s\t%.2f\t%.2f\t%.2f\n", id, name, basic, bonus,updated);
    }
    printf("Salary report generated in 'salary_report.txt'.\n");
    printf("Total Salary Expenditure after bonuses: %.2f\n", totalExpenditure);
    fclose(inFile);
    fclose(outFile);
    return 0;
}
