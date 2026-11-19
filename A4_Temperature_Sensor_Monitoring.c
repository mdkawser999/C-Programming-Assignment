#include <stdio.h>

void findMinMax(float *arr, int size, float *max, float *min)
{
    *max = *arr;
    *min = *arr;
    for (int i = 1; i < size; i++)
    {
        if (*(arr + i) > *max){
            *max = *(arr + i);
        }
        if (*(arr + i) < *min){
            *min = *(arr + i);
        }
    }
}
int main()
{
    float temps[5], maxTemp, minTemp;
    float *ptr = temps;
    printf("Enter 5 temperature readings:\n");

    for (int i = 0; i < 5; i++)
    {
        scanf("%f", (ptr + i));
    }

    findMinMax(ptr, 5, &maxTemp, &minTemp);

    printf("\nTemperature Readings: ");

    for (int i = 0; i < 5; i++)
    {
        printf("%.2f ", *(ptr + i));
    }
    printf("\nMaximum Temperature: %.2f\n", maxTemp);
    printf("Minimum Temperature: %.2f\n", minTemp);
    return 0;
}