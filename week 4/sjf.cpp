// shortest job first search (sjf)
#include<stdio.h>
#define max 10
int main() {
    int n,i,j,temp,p[max],bt[max],tat[max],wt[max];
    float awt=0, atat=0;
    printf("enter no of processes : ");
    scanf("%d",&n);
    printf("enter arrival time of %d process : ",n);
    for(i=0; i<n; i++) {
        scanf("%d",&p[i]);
    }
    printf("enter burst time of %d process : ",n);
    for(i=0; i<n; i++) {
        scanf("%d",&bt[i]);
    }
    // applying bubble sort techinique to sort according to their burst time
    for(i=0; i<n; i++) {
        for(j=0; j<n-i-1; j++) {
            if(bt[j] > bt[j+1]) {
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
                
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    printf("process arrival_time burst_time turnaround_time waiting_time\n");
    for(i=0; i<n; i++) {
        wt[i]=0;
        tat[i]=0;
        for(j=0; j<i; j++) {
            wt[i] = wt[i] +bt[j];
        }
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,p[i],bt[i],tat[i],wt[i]);
    }
    awt = awt /n;
    atat = atat /n ;
    printf("average turnaround_time : %f\n",atat);
    printf("average waiting_time : %f\n",awt);
}

