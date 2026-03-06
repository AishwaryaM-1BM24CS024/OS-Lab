#include <stdio.h>
struct Process{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int completed;
};
int main(){
    struct Process p[20];
    int n,i,time=0,completed=0,min_bt,index;
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
        p[i].completed=0;
    }
    while(completed != n){
        min_bt=9999;
        index=-1;
        for(i=0;i<n;i++){
            if(p[i].at <= time && p[i].completed == 0 && p[i].bt < min_bt){
                min_bt = p[i].bt;
                index=i;
            }
        }
        if(index != -1){
            time += p[index].bt;
            p[index].ct=time;
            p[index].tat=p[index].ct-p[index].at;
            p[index].wt=p[index].tat-p[index].bt;

            avg_wt += p[index].wt;
            avg_tat += p[index].tat;

            p[index].completed =1;
            completed++;
        }else{
            time++;
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
