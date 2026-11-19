#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, extra, total;
    float *marks, sum = 0;
    printf("Enter initial number of students: ");
    scanf("%d", &n);

    marks = (float *)malloc(n * sizeof(float));

    if (marks == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter marks for student %d: ", i + 1);
        scanf("%f", &marks[i]);
        sum += marks[i];
    }
    printf("\nHow many more students to add? ");
    scanf("%d", &extra);
    
    total = n + extra;
    if (extra > 0)
    {
        float *temp = (float *)realloc(marks, total * sizeof(float));
        if (temp == NULL)
        {
            printf("Memory reallocation failed!\n");
            free(marks);
            return 1;
        }
        marks = temp;
        for (int i = n; i < total; i++)
        {
            printf("Enter marks for student %d: ", i + 1);
            scanf("%f", &marks[i]);
            sum += marks[i];
        }
    }
    printf("\nAverage marks of all %d registered students: %.2f\n", total, sum / total);
    free(marks);
    return 0;
}
