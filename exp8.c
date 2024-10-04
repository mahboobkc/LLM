#include <stdio.h>

#define MAX_P 10
#define MAX_R 10

int isSafe(int processes[], int available[], int max[][MAX_R], int allocation[][MAX_R], int n, int m) {
    int need[MAX_P][MAX_R];
    int finish[MAX_P] = {0};
    int work[MAX_R];
    int i, j, count = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    for (i = 0; i < m; i++) {
        work[i] = available[i];
    }

    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int canAllocate = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = 0;
                        break;
                    }
                }
                
                if (canAllocate) {
                    for (j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = 1;
                    processes[count++] = i;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            break;
        }
    }

    if (count < n) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int n, m;
    int allocation[MAX_P][MAX_R];
    int max[MAX_P][MAX_R];
    int available[MAX_R];

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    printf("Enter allocation matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter max matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter available vector:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }
        printf("Need Matrix:\n");
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        	printf ("%d  ",  max[i][j] - allocation[i][j]);	;
        	}
        	printf("\n");
        }

    int processes[MAX_P];

    if (isSafe(processes, available, max, allocation, n, m)) {
        printf("Safe state\n");
        printf("Safe sequence:");
        for (int i = 0; i < n; i++) {
            printf(" P%d", processes[i]);
        }
        printf("\n");
    } else {
        printf("Unsafe state\n");
    }

    return 0;
}

