//round robin algorithm
#include <stdio.h>

int main() {
    int n, i, qt, count = 0, sq = 0, bt[10], wt[10], tat[10], rem_bt[10];
    float awt = 0, atat = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time of %d processes:\n", n);
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i]; // initialize remaining burst time
    }

    printf("Enter time quantum: ");
    scanf("%d", &qt);

    while (1) {
        int done = 1; // flag to check if all processes are done

        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; // there is a pending process

                if (rem_bt[i] > qt) {
                    sq = sq + qt;
                    rem_bt[i] = rem_bt[i] - qt;
                } else {
                    sq = sq + rem_bt[i];
                    rem_bt[i] = 0;
                    tat[i] = sq; // complete time for this process
                }
            }
        }

        if (done == 1)
            break;
    }

    printf("Process\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i]; // waiting time
        awt += wt[i];
        atat += tat[i];
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], tat[i], wt[i]);
    }

    awt /= n;
    atat /= n;
    printf("Average Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", atat);

    return 0;
}

