#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
    int tat;
    int wt;
    int exist;
};

int main() {

    int n, tq, t = 0, completed = 0;

    struct Process p[10];

    int queue[100], front = 0, rear = 0;

    float avg_tat = 0, avg_wt = 0;

    printf("Enter Total Process: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival and Burst Time for P%d: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);

        p[i].pid = i + 1;
        p[i].rt = p[i].bt;
        p[i].exist = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    for (int i = 0; i < n; i++) {
        if (p[i].at <= t) {
            queue[rear++] = i;
            p[i].exist = 1;
        }
    }

    while (front < rear) {

        int i = queue[front++];

        if (p[i].rt > tq) {
            t += tq;
            p[i].rt -= tq;
        }
        else {
            t += p[i].rt;
            p[i].rt = 0;
            completed++;

            p[i].ct = t;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
        }

        for (int j = 0; j < n; j++) {
            if (p[j].at <= t && p[j].exist == 0) {
                queue[rear++] = j;
                p[j].exist = 1;
            }
        }
        if (p[i].rt > 0) {
            queue[rear++] = i;
        }
        if (front == rear && completed < n) {
            for (int j = 0; j < n; j++) {
                if (p[j].exist == 0) {
                    t = p[j].at;
                    queue[rear++] = j;
                    p[j].exist = 1;
                    break;
                }
            }
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt);

        avg_tat += p[i].tat;
        avg_wt += p[i].wt;
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Waiting Time = %.2f", avg_wt);

    return 0;
}
