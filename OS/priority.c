#include<stdio.h>
typedef struct
{
int no,at,bt,tat,wt,pt;
}process;
process p[10];
int main()
{
int i,n,temp[10],t,count=0,sp;
int total_tat=0, total_wt=0;
float avg_tat, avg_wt;
printf("Enter the no: of processes : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter arrival time, burst time and priority of process P%d : ",i);
scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].pt);
p[i].no = i;
temp[i] = p[i].bt;
}
p[9].pt = 1000000;
for(t=0;count!=n;t++)
{
sp = 9;
for(i=0;i<n;i++)
{
if(p[sp].pt>p[i].pt && p[i].at<=t && p[i].bt>0)
{
sp =i;
}
}
p[sp].bt = p[sp].bt-1;
if(p[sp].bt==0)
{
count++;
p[sp].tat = t+1-p[sp].at;
p[sp].wt = p[sp].tat - temp[sp];
total_tat +=p[sp].tat;
total_wt+=p[sp].wt;
}
}
avg_tat = (float)total_tat/n;
avg_wt = (float)total_wt/n;
printf("Process\tArrival time\tBurst time\tPriority\tTurn aroundtime\tWaiting time\n");
for(i=0;i<n;i++)
{
printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,p[i].at,temp[i],p[i].pt,
p[i].tat,p[i].wt);
}
printf("Average turn around time = %.2f\n",avg_tat);
printf("Average waiting time = %.2f\n",avg_wt);
return 0;
}
