#include<stdio.h>
void main()
{
int pid[20],bt[20],wt[20],tt[20],n,i,j,temp=0,priority[20];
float wt_avg,tt_avg;
printf("enter the no: of processes\n");
scanf("%d",&n);
printf("enter the burst time of the processes\n");
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
}
printf("enter the process id of the processes\n");
for(i=0;i<n;i++)
{
scanf("%d",&pid[i]);
}
printf("Enter the priority of the processes\n");
for(i=0;i<n;i++)
{
scanf("%d",&priority[i]);
}
for(i=0;i<n-1;i++)
{
 for(j=0;j<n-i-1;j++)
 {
  if(priority[j]>priority[j+1])
  {
   temp=bt[j];
   bt[j]=bt[j+1];
   bt[j+1]=temp;
   temp=pid[j];
   pid[j]=pid[j+1];
   pid[j+1]=temp;
   temp=priority[j];
   priority[j]=priority[j+1];
   priority[j+1]=temp;
  }
 }
}
wt[0]=0;
for(i=0;i<n;i++)
{
wt[i]=wt[i-1]+bt[i-1];
wt_avg+=wt[i];
}
wt_avg/=n;
for(i=0;i<n;i++)
{
tt[i]=wt[i]+bt[i];
tt_avg+=tt[i];
}
tt_avg/=n;
printf("PID\tBT\tWT\tTT\n");
for(i=0;i<n;i++)
{
 printf("%d\t%d\t%d\t%d\t\n",pid[i],bt[i],wt[i],tt[i]);
}
printf("\n----------------------------\n");
for(i=0;i<n;i++)
{
printf("|P%d|\t",pid[i]);
}
printf("\n----------------------------\n");
printf("%d\t",wt[0]);
for(i=0;i<n;i++)
{
printf("%d\t",tt[i]);
}
printf("\n");
printf("the average waiting time is%f\n",wt_avg);
printf("the average turn around time is%f",tt_avg);
}
