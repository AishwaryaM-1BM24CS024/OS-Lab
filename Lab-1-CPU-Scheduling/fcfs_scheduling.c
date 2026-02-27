#include<stdio.h>
struct Process{
    int pid;
    int arrival;
    int burst;
    int completion;
    int waiting;
    int turnaround;
};
int main(){
    int n,i,j;
    struct Process p[100],temp;

    printf("enter number of processes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\n");
        printf("P%d\n",i+1);
        p[i].pid=i+1;
        printf("enter arrival\n");
        scanf("%d",&p[i].arrival);
        printf("enter burst\n");
        scanf("%d",&p[i].burst);
    }

    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j].arrival > p[j+1].arrival){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }

    }

    int current=0;

    for(i=0;i<n;i++){
        if(current<p[i].arrival){
            current=p[i].arrival;
        }
        p[i].completion=current+p[i].burst;
        p[i].turnaround=p[i].completion-p[i].arrival;
        p[i].waiting=p[i].turnaround-p[i].burst;

        current =p[i].completion;
    }

    float totalWT = 0, totalTAT = 0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].completion,
               p[i].turnaround,
               p[i].waiting);

        totalWT += p[i].waiting;
        totalTAT += p[i].turnaround;
    }

    printf("\naverage waiting time = %.2f", totalWT / n);
    printf("\naverage turnaround time = %.2f\n", totalTAT / n);

    return 0;

}
