#include <stdio.h>
 struct Process {
 int id;
 int burstTime;
 int priority;
 int waitingTime;
 int turnaroundTime;
 };
 // Function to sort the processes based on priority
 void sortProcessesByPriority(struct Process p[], int n) {
 struct Process temp;
 for (int i = 0; i < n- 1; i++) {
 for (int j = i + 1; j < n; j++) {
 if (p[i].priority > p[j].priority) {
 temp = p[i];
 p[i] = p[j];
 p[j] = temp;
 }}}}
 // Function to calculate waiting and turnaround times
 void calculateTimes(struct Process p[], int n) {
 p[0].waitingTime = 0;
 for (int i = 1; i < n; i++) {
 p[i].waitingTime = p[i- 1].waitingTime + p[i- 1].burstTime; }
 for (int i = 0; i < n; i++) {
 p[i].turnaroundTime = p[i].waitingTime + p[i].burstTime;
 }}
 void printResults(struct Process p[], int n) {
 printf("ID\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
 for (int i = 0; i < n; i++) {
printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].priority, p[i].burstTime, p[i].waitingTime,
 p[i].turnaroundTime);
 }}
 int main() {
 int n;
 printf("Enter the number of processes: ");
 scanf("%d", &n);
 struct Process p[n];
 for (int i = 0; i < n; i++) {
 printf("Enter burst time and priority for process %d: ", i + 1);
 p[i].id = i + 1;
 scanf("%d %d", &p[i].burstTime, &p[i].priority);
 }
 // Sort processes by priority
 sortProcessesByPriority(p, n);
 // Calculate waiting and turnaround times
 calculateTimes(p, n);
 // Print results
 printResults(p, n);
 return 0;
 }