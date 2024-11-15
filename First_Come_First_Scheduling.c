#include<stdio.h>
#include<stdlib.h>
int i;

void findWT(int n , int wt[],int brustTime[]){
    wt[0] = 0;
    for(i=1;i<n;i++){
        wt[i] = wt[i-1] + brustTime[i-1];
    }
}

void findTT(int n , int wt[],int brustTime[],int tt[]){
    for(i=0;i<n;i++){
        tt[i] = wt[i] + brustTime[i];
    }
}


void findAvgTime(int processes[],int n,int brustTime[]){
    int wt[n] , tt[n], twt = 0 , ttt = 0;

    findWT(n,wt,brustTime);
    findTT(n,wt,brustTime,tt);

    printf("First Come First Scheduling \n");
    printf("Process \t Burst Time \t Waiting Time \t TurnAround Time \n");
    for(i=0;i<n;i++){
        printf("%d \t\t\t\t %d \t\t\t\t %d \t\t\t\t %d \n", i+1,brustTime[i],wt[i],tt[i]);
    }
    for(i=0;i<n;i++){
        twt = twt + wt[i];
        ttt = ttt + tt[i];
    }
   printf("\n");
    printf("Average waiting time : %.2f \n",(float)twt/n);
    printf("Average turnaround time : %.2f \n",(float)ttt/n);
}




int main(){
    int n;
    printf("Enter the number of Processes: ");
    scanf("%d",&n);
    int processes[n],burstTime[n];
    
    for(i=0;i<n;i++){
     printf("Enter the burst time for process %d: ",i+1);
     scanf("%d",&burstTime[i]);
    }

    findAvgTime(processes,n,burstTime);
    return 0;
}