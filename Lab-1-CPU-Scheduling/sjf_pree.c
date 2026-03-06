#include <stdio.h>
struct Process{
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
    int tat;
    int wt;
};
int main(){
    struct Process p[20];
    int n,i,time=0,completed=0,shortest,min_rt;
    float avg_wt=0,avg_tat=0;
    printf("enter no of process: \n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\n");
        printf("P%d\n",i+1);
        p[i].pid=i+1;
        printf("enter arrival time \n");
        scanf("%d",&p[i].at);
        printf("enter burst time: \n");
        scanf("%d",&p[i].bt);
        p[i].rt=p[i].bt;
    }
    while(completed != n){
        shortest=-1;
        min_rt=9999;
        for(i=0;i<n;i++){
            if(p[i].at <= time && p[i].rt>0 && p[i].rt<min_rt){
                min_rt=p[i].rt;
                shortest=i;
            }
        }
        if(shortest == -1){
            time++;
            continue;
        }
        p[shortest].rt--;
        time++;
        if(p[shortest].rt == 0){
            completed++;
            p[shortest].ct=time;
            p[shortest].tat=p[shortest].ct-p[shortest].at;
            p[shortest].wt=p[shortest].tat-p[shortest].bt;

            avg_tat+=p[shortest].tat;
            avg_wt += p[shortest].wt;
        }
    }
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

    }
    printf("\naverage turnaround time = %.2f\n",avg_tat/n);
    printf("\naverage waiting time = %.2f\n",avg_wt/n);
    return 0;
}
