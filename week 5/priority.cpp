// priority scheduling
#include <stdio.h>
#define max 100
int main() {
    int n,i,j,k=1,t,b=0,min,temp[max],bt[max],wt[max],tat[max],at[max],pr[max];
    float awt=0, atat=0;
    printf("enter no of processes : ");
    scanf("%d",&n);
    printf("enter arrival time of %d processes : ",n);
    for(i=0; i<n; i++) {
        printf("P%d -> ",i);
        scanf("%d",&at[i]);
    }
    printf("enter burst time of %d processes : ",n);
    for(i=0; i<n; i++) {
        printf("P%d -> ",i);
        scanf("%d",&bt[i]);
    }
    printf("enter priority of %d processes : ",n);
    for(i=0; i<n; i++) {
        printf("P5%d -> ",i);
        scanf("%d",&pr[i]);
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(at[i] < at[j]) {
                t=at[j];
                at[j]=at[i];
                at[i]=t;
                
                t=bt[j];
                bt[j]=bt[i];
                bt[i]=t;
        	}
    	}
	}
    for(j=0; j<n; j++) {
        b=b+bt[j];
        min=bt[k];
        for(i=k; i<n; i++) {
            min=pr[k];
            if(b>=at[i]) {
                if(pr[i] < min) {
                    t=at[k];
                    at[k]=at[i];
                    at[i]=t;
                    
                    t=bt[k];
                    bt[k]=bt[i];
                    bt[i]=t;
                    
                    t=pr[k];
                    pr[k]=pr[i];
                    pr[i]=t;
                }
            }
        }
        k++;
    }
    temp[0]=0;
    printf("Process arrival_time burst_time priority turnaround_time waiting_time\n");
    for(i=0; i<n; i++) {
        wt[i]=0;
        tat[i]=0;
        temp[i+1] = temp[i] + bt[i];
        wt[i] = temp[i] - at[i];
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("%d\t\t %d\t\t\t %d\t\t\t %d\t\t\t %d\t\t\t %d\n",i+1,at[i],bt[i],pr[i],tat[i],wt[i]);
    }
    awt = awt /n;
    atat = atat/n;
    printf("average turnaround time : %f\n",atat);
    printf("average waiting time : %f",awt);
    
}
