#include<stdio.h>
void main()
{
int pid[20],bt[20],wt[20],tt[20],n,i,j;
float wt_avg,tt_avg;
printf("enter the no: of processes\n");
scanf("%d",&n);
printf("enter the burst time and the process id of the processes\n");
for(i=1;i<n;i++)
{
scanf("%d",&bt[i]);
scanf("%d",&pid[i]);
}
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=wt[i-1]+bt[i-1];
wt_avg+=wt[i];
}
wt_avg/=n;
for(i=1;i<n;i++)
{
tt[i]=wt[i]+bt[i];
tt_avg+=tt[i];
}
tt_avg/=n;
printf("\n----------------------------\n");
for(i=1;i<n;i++)
{
printf("|P%d|\t",pid[i]);
}
printf("\n----------------------------\n");
for(i=1;i<n;i++)
{
printf("%d\t",tt[i]);
}
printf("\n");
printf("the average waiting time is%f",wt_avg);
printf("the average turn around time is%f",tt_avg);
}
