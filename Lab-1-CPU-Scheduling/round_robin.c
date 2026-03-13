#include<stdio.h>
int main() {
int n, tq, t = 0, completed = 0;
int at[10], bt[10], rt[10], ct[10], tat[10], wt[10];
int exist[10] = {0};
int queue[100], front = 0, rear = 0;
float avg_tat=0,avg_wt=0;
printf("Enter Total Process: ");
scanf("%d", &n);

for (int i = 0; i < n; i++) {
    printf("Enter Arrival and Burst Time for P%d: ", i + 1);
    scanf("%d %d", &at[i], &bt[i]);
    rt[i] = bt[i];
}

printf("Enter Time Quantum: ");
scanf("%d", &tq);

for (int i = 0; i < n; i++) {
    if (at[i] <= t) {
        queue[rear++] = i;
        exist[i] = 1;
    }
}
while (front < rear) {
    int i = queue[front++];
    if (rt[i] > tq) {
        t += tq;
        rt[i] -= tq;
    }
    else {
        t += rt[i];
        rt[i] = 0;
        completed++;

        ct[i] = t;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
  
    for (int j = 0; j < n; j++) {
        if (at[j] <= t && exist[j] == 0) {
            queue[rear++] = j;
            exist[j] = 1;
        }
    }
    if (rt[i] > 0) {
        queue[rear++] = i;
    }
    if (front == rear && completed < n) {
        for(int j = 0; j < n; j++) {
            if(exist[j] == 0) {
                t = at[j];
                queue[rear++] = j;
                exist[j] = 1;
                break;
            }
        }
    }
}
