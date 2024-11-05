#include <stdio.h>
 void findWaitingTime(int n, int burstTime[], int waitingTime[]) {
 waitingTime[0] = 0; // Waiting time for the first process is 0
 // Calculate waiting time for each process
 for (int i = 1; i < n; i++) {
 waitingTime[i] = burstTime[i- 1] + waitingTime[i- 1];
 }
 }
 void findTurnaroundTime(int n, int burstTime[], int waitingTime[], int turnaroundTime[]) {
 // Calculate turnaround time for each process
 for (int i = 0; i < n; i++) {
 turnaroundTime[i] = burstTime[i] + waitingTime[i];
 }
 }
void findAverageTime(int n, int burstTime[]) {
 int waitingTime[n], turnaroundTime[n];
 int totalWaitingTime = 0, totalTurnaroundTime = 0;
 // Sort the burst times in ascending order for SJF scheduling
 for (int i = 0; i < n- 1; i++) {
 for (int j = i + 1; j < n; j++) {
 if (burstTime[i] > burstTime[j]) {
 // Swap burstTime[i] and burstTime[j]
 int temp = burstTime[i];
 burstTime[i] = burstTime[j];
 burstTime[j] = temp;
 }
 }
 }
 // Calculate waiting time for all processes
 findWaitingTime(n, burstTime, waitingTime);
 // Calculate turnaround time for all processes
 findTurnaroundTime(n, burstTime, waitingTime, turnaroundTime);
 // Display process details
 printf("Processes\tBurst Time\tWaiting Time\tTurnaround Time\n");
 for (int i = 0; i < n; i++) {
 totalWaitingTime += waitingTime[i];
 totalTurnaroundTime += turnaroundTime[i];
 printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], waitingTime[i], turnaroundTime[i]);
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
 int burstTime[n];
// Input burst time for each process
 for (int i = 0; i < n; i++) {
 printf("Enter burst time for process %d: ", i + 1);
 scanf("%d", &burstTime[i]);
 }
 // Calculate average time using SJF scheduling
 findAverageTime(n, burstTime);
 return 0;
 }