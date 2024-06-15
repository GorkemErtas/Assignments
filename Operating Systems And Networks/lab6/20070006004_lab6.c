#include <stdio.h>

int main() {
    int i, n, burstTime[20], priority[20], waitingTime[20], turnaroundTime[20];
    float avgWaitingTime = 0, avgTurnaroundTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time and priority for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Burst time: ");
        scanf("%d", &burstTime[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
    }

    waitingTime[0] = 0;
    turnaroundTime[0] = burstTime[0];

    for (i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];
    }

    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    printf("\npno \tbtime     \tatime     \twtime     \tttime\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], priority[i], waitingTime[i], turnaroundTime[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avgWaitingTime);
    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaroundTime);

    return 0;
}
