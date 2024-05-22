// c program to implement fcfs scheduling algorithm
#include<stdio.h>
#define max 100
int main() {
    int i,n,at[max],bt[max],tat[max],wt[max],temp[max];
    float atat=0, awt=0;
    printf("enter no of processes : ");
    scanf("%d",&n);
    printf("enter arrival time of %d processes : ",n);
    for(i=0; i<n; i++) {
        scanf("%d",&at[i]);
    }
    printf("enter burst time of %d processes : ",n);
    for(i=0; i<n; i++) {
        scanf("%d",&bt[i]);
    }
    temp[0]=0;
    printf("process arriva_time burst_time turnaround_time waiting_time\n");
    for(i=0; i<n; i++) {
        wt[i]=0;
        tat[i]=0;
        temp[i+1] = temp[i] + bt[i];
        wt[i] = temp[i] - at[i];
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("P%d\t\t %d\t\t\t %d\t\t\t %d\t\t\t\t %d\n",i+1,at[i],bt[i],tat[i],wt[i]);
    }
    awt = awt / n;
    atat = atat / n;
    printf("average turnaround_time : %f\n",atat);
    printf("average waiting_time : %f\n",awt);
}
