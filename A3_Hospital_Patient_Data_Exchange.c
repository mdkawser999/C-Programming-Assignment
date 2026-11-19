#include <stdio.h>

void swapPatientID(int *id1, int *id2)
{
    int temp = *id1;
    *id1 = *id2;
    *id2 = temp;
}
int main()
{
    int patient1, patient2;

    printf("Enter Patient ID for Department 1: ");
    scanf("%d", &patient1);

    printf("Enter Patient ID for Department 2: ");
    scanf("%d", &patient2);

    printf("\nBefore Swapping: Dept 1 ID = %d, Dept 2 ID = %d\n", patient1, patient2);

    swapPatientID(&patient1, &patient2);

    printf("After Swapping: Dept 1 ID = %d, Dept 2 ID = %d\n", patient1, patient2);
    return 0;
}
