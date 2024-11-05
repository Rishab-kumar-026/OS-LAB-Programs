 #include <stdio.h>
 void findWaitingTime(int processes[], int n, int burstTime[], int waitingTime[]) {
 // Waiting time for first process is 0
 waitingTime[0] = 0;
 // Calculating waiting time for each process
 for (int i = 1; i < n; i++) {
 waitingTime[i] = burstTime[i- 1] + waitingTime[i- 1];
 }
 }
 void findTurnaroundTime(int processes[], int n, int burstTime[], int waitingTime[], int
 turnaroundTime[]) {
 // Calculating turnaround time for each process
 for (int i = 0; i < n; i++) {
 turnaroundTime[i] = burstTime[i] + waitingTime[i];
 }
 }
 void findAverageTime(int processes[], int n, int burstTime[]) {
 int waitingTime[n], turnaroundTime[n], totalWaitingTime = 0, totalTurnaroundTime = 0;
 // Calculate waiting time for all processes
 findWaitingTime(processes, n, burstTime, waitingTime);
 // Calculate turnaround time for all processes
 findTurnaroundTime(processes, n, burstTime, waitingTime, turnaroundTime);
 // Display process details
 printf("Processes\tBurst Time\tWaiting Time\tTurnaround Time\n");
 for (int i = 0; i < n; i++) {
 totalWaitingTime += waitingTime[i];
 totalTurnaroundTime += turnaroundTime[i];
 printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i], burstTime[i], waitingTime[i],
 turnaroundTime[i]);
 }
 // Calculate and display average waiting time and average turnaround time
 printf("\nAverage Waiting Time: %.2f", (float)totalWaitingTime / n);
 printf("\nAverage Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
}
 int main() {
 int n;
 // Input the number of processes
 printf("Enter the number of processes: ");
 scanf("%d", &n);
 int processes[n], burstTime[n];
 // Input burst time for each process
 for (int i = 0; i < n; i++) {
 processes[i] = i + 1;
 printf("Enter burst time for process %d: ", i + 1);
 scanf("%d", &burstTime[i]);
 }
 // Calculate average time using FCFS scheduling
 findAverageTime(processes, n, burstTime);
 return 0;
 }