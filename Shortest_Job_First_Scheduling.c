#include <stdio.h>
#include <stdlib.h>
int i, j, temp;

void findWT(int n, int wt[], int bt[])
{
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
}

void findTT(int n, int wt[], int bt[], int tt[])
{
    for (i = 0; i < n; i++)
    {
        tt[i] = wt[i] + bt[i];
    }
}

void findAvgTime(int n, int bt[])
{
    int wt[n], tt[n], twt = 0, ttt = 0;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (bt[i] > bt[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    findWT(n, wt, bt);
    findTT(n, wt, bt, tt);

    printf("Shortest Job First Scheduling \n");
    printf("Process \t Brust Time \t Waiting Time \t Turnaround Time \n");
    for (i = 0; i < n; i++)
    {
        printf("%d \t\t\t\t %d \t\t\t\t %d \t\t\t\t %d \n", i + 1, bt[i], wt[i], tt[i]);
    }

    for (i = 0; i < n; i++)
    {
        twt += wt[i];
        ttt += tt[i];
    }

    printf("Average Waiting Time : %.2f \n", (float)twt / n);
    printf("Average Turnaround Time : %.2f \n", (float)ttt / n);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the burst time for process %d: " , i+1);
        scanf("%d", &bt[i]);
    }
    findAvgTime(n, bt);
    return 0;
}