#include <stdio.h>
void displayMarks(float *ptr, int n)
{
    printf("\nStudent Marks:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Student %d: %.2f\n", i + 1, *(ptr + i));
    }
}
int main()
{
    float marks[10];
    float *ptr = marks;
    int studentNum;
    float newMark, sum = 0;

    printf("Enter marks for 10 students:\n");

    for (int i = 0; i < 10; i++)
    {
        printf("Student %d: ", i + 1);
        scanf("%f", (ptr + i));
    }

    displayMarks(ptr, 10);

    printf("\nEnter student number to modify marks (1-10): ");
    scanf("%d", &studentNum);

    if (studentNum >= 1 && studentNum <= 10)
    {
        printf("Enter corrected marks: ");
        scanf("%f", &newMark);
        *(ptr + (studentNum - 1)) = newMark;
    }
    else
    {
        printf("Invalid student number!\n");
    }

    displayMarks(ptr, 10);

    for (int i = 0; i < 10; i++)
    {
        sum += *(ptr + i);
    }

    printf("\nClass Average after correction: %.2f\n", sum / 10.0);
    return 0;
}
