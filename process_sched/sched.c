#include <stdio.h>
int main()
{
    int n, sum, wt, tat, twt, ttat;
    int t[10];
    float avgWt, avgTAT;
    printf("Enter total number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter burst time of process %d: ", i + 1);
        scanf("%d", &t[i]);
    }
    printf("\n\n First come First Serve algorithm \n\n");
    printf("Process ID\t\tWaiting time\t\tTurnAround time\n");
    printf("1\t\t0\t\t%d\n", t[0]);
    sum = 0;
    wt = 0;
    twt = 0;
    ttat = t[0];
    for (int i = 1; i < n; i++)
    {
        sum += t[i - 1];
        wt = sum;
        tat = sum + t[i];
        twt += wt;
        ttat += tat;
        printf("%d\t\t%d\t\t%d\n", i + 1, wt, tat);
    }
    avgWt = (float)twt / n;
    avgTAT = (float)ttat / n;
    printf("Avg waiting time is %f\n", avgWt);
    printf("Avg turnaround time is %f\n", avgTAT);
    return 0;
}