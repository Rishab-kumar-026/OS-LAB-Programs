#include<stdio.h>
int i,j;
struct Process{
    int id,bt,wt,tt,pr;
};

 void sortPriority(struct Process p[], int n){
    struct Process temp;
    for(i=0;i<n-1;i++){
        for(j=1;j<n;j++){
            if(p[j].pr > p[i].pr){
               temp = p[i];
               p[i] = p[j];
               p[j] = temp;
            }
        }
    }
 }

 void calculateTime(struct Process p[],int n){
    p[0].wt = 0;
    for(i=1;i<n;i++){
        p[i].wt = p[i-1].wt + p[i-1].bt;
    }
    for(i=0;i<n;i++){
        p[i].tt = p[i].wt + p[i].bt;
    }
 }

 void displayResult(struct Process p[],int n){
    printf("Priority Scheduling \n");
    printf("Process ID \t Priority \t Burst Time \t Waiting Time \t Turnaround Time \n");
    for(i=0;i<n;i++){
        printf("%d \t\t\t\t %d \t\t\t\t %d \t\t\t\t %d \t\t\t\t %d \t\t\t\t \n",p[i].id,p[i].pr,p[i].bt,p[i].wt,p[i].tt);
    }
 }


int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    
    struct Process p[n];

    for(i=0;i<n;i++){
        p[i].id = i+1;
        printf("Enter priority & brust time of process %d: ",i+1);
        scanf("%d %d",&p[i].pr,&p[i].bt);
    }

    sortPriority(p,n);
    calculateTime(p,n);
    displayResult(p,n);
    return 0;
}