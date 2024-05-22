#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int processes, resources;
int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];

void calculateNeed() {
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

bool isSafe() {
    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES] = {0};
    
    for (int i = 0; i < resources; i++) {
        work[i] = available[i];
    }
    
    while (true) {
        bool found = false;
        for (int i = 0; i < processes; i++) {
            if (!finish[i]) {
                bool possible = true;
                for (int j = 0; j < resources; j++) {
                    if (need[i][j] > work[j]) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    for (int j = 0; j < resources; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            for (int i = 0; i < processes; i++) {
                if (!finish[i]) {
                    return false;
                }
            }
            return true;
        }
    }
}

bool requestResources(int process, int request[]) {
    for (int i = 0; i < resources; i++) {
        if (request[i] > need[process][i]) {
            printf("Error: Process has exceeded its maximum claim.\n");
            return false;
        }
        if (request[i] > available[i]) {
            printf("Resources are not available.\n");
            return false;
        }
    }

    for (int i = 0; i < resources; i++) {
        available[i] -= request[i];
        allocation[process][i] += request[i];
        need[process][i] -= request[i];
    }

    if (isSafe()) {
        return true;
    }

    for (int i = 0; i < resources; i++) {
        available[i] += request[i];
        allocation[process][i] -= request[i];
        need[process][i] += request[i];
    }

    printf("The system is not in a safe state after allocation. Rolling back.\n");
    return false;
}

int main() {
    printf("Enter the number of processes: ");
    scanf("%d", &processes);
    printf("Enter the number of resources: ");
    scanf("%d", &resources);

    printf("Enter the available resources:\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &available[i]);
    }

    printf("Enter the maximum resource matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &maximum[i][j]);
        }
    }

    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    calculateNeed();

    int process;
    printf("Enter the process number for resource request (0-%d): ", processes - 1);
    scanf("%d", &process);

    int request[MAX_RESOURCES];
    printf("Enter the resource request:\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &request[i]);
    }

    if (requestResources(process, request)) {
        printf("The resources have been allocated safely.\n");
    } else {
        printf("The resources could not be allocated.\n");
    }

    return 0;
}

