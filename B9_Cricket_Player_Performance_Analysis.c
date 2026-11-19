#include <stdio.h>
struct Player
{
    char name[50];
    int matches;
    int totalRuns;
    int highestScore;
    float average;
};
int main()
{
    struct Player p[11];
    int bestIdx = 0;
    for (int i = 0; i < 11; i++)
    {
        printf("\nPlayer %d Name: ", i + 1);
        scanf(" %[^\n]", p[i].name);

        printf("Matches Played: ");
        scanf("%d", &p[i].matches);

        printf("Total Runs: ");
        scanf("%d", &p[i].totalRuns);

        printf("Highest Score: ");
        scanf("%d", &p[i].highestScore);

        if (p[i].matches > 0){
            p[i].average = (float)p[i].totalRuns / p[i].matches;
        }else{
            p[i].average = 0;
        }
        if (p[i].average > p[bestIdx].average)
        {
            bestIdx = i;
        }
    }
    printf("\n--- Player Averages ---\n");

    for (int i = 0; i < 11; i++)
    {
        printf("%s -> Avg Runs/Match: %.2f\n", p[i].name, p[i].average);
    }
    printf("\nHighest Average Player: %s (Average: %.2f, Highest Score: %d)\n",
           p[bestIdx].name, p[bestIdx].average, p[bestIdx].highestScore);
    return 0;
}
