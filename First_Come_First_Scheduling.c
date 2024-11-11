#include <stdio.h>
int i;
int findWaitingTime(int processes[], int n, int burstTime[], int waitingTime[])
{
    waitingTime[0] = 0;
    for (i = 1; i < n; i++)
    {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }
}

int findTurnAroundTime(int processes[], int n, int burstTime[], int waitingTime[], int turnAroundTime[])
{
    for (i = 0; i < n; i++)
    {
        turnAroundTime[i] = waitingTime[i] + burstTime[i];
    }
}

int findAverageTime(int processes[], int n, int burstTime[])
{
    int waitingTime[n], turnAroundTime[n], totalWaitingTime = 0, totalTurnAroundTime = 0;

    findWaitingTime(processes, n, burstTime, waitingTime);
    findTurnAroundTime(processes, n, burstTime, waitingTime, turnAroundTime);

    printf("Processes \t WaitingTime \t BurstTime \t TurnAroundTime");
    printf("\n");
    for (i = 0; i < n; i++)
    {
        totalWaitingTime = totalWaitingTime + waitingTime[i];
        totalTurnAroundTime = totalTurnAroundTime + turnAroundTime[i];

        printf("%d \t %d \t %d \t %d", processes[i], waitingTime[i], burstTime[i], turnAroundTime[i]);
        printf("\n");
    }
    printf("\n");
    printf("Average Waiting Time: %.2f", (float)totalWaitingTime / n);
    printf("\n Average TurnAround Time: %.2f", (float)totalTurnAroundTime / n);
}

int main()
{
    int n;
    printf("Enter the number of Process: ");
    scanf("%d", &n);

    int processes[n], burstTime[n];

    for (i = 0; i < n; i++)
    {
        processes[i] = i + 1;
        printf("Enter the Burst Time for Process %d : ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    findAverageTime(processes, n, burstTime);
    return 0;
}