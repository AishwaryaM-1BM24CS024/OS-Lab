#include<stdio.h>
struct Process{
    int pid;
    int at,bt,pr;
    int ct,tat,wt;
    int done;
};
int main(){
    int n,i,time=0,completed=0,idx;
    float avg_tat=0,avg_wt=0;
    struct Process p[20];
    printf("enter number of process: \n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p[i].pid=i+1;
        printf("\nP%d\n",p[i].pid);
        printf("enter at bt and priority :\n");
        scanf("%d %d %d",&p[i].at,&p[i].bt,&p[i].pr);

        p[i].done=0;
    }
    while(completed < n){
        idx=-1;
        for(i=0;i<n;i++){
            if(p[i].at <= time && p[i].done ==0){
                if(idx == -1 || p[i].pr < p[idx].pr){
                    idx=i;
                }
            }
        }
        if(idx == -1){
            time++;
        }else{
            time += p[idx].bt;
            p[idx].ct=time;
            p[idx].tat=p[idx].ct-p[idx].at;
            p[idx].wt=p[idx].tat - p[idx].bt;
            p[idx].done=1;
            avg_tat += p[idx].tat;
            avg_wt += p[idx].wt;
            completed++;

        }
    }
    printf("\nPID\tAT\tBT\tPRI\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].pr,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("\n");
    printf("Average Turnaround time : %.2f ",avg_tat/n);
    printf("Average waiting time : %.2f ",avg_wt/n);
    return 0;
}

