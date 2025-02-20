#include<stdio.h>
int main()
{
 int n,at[10],bt[10],temp[10],P[10],wt[10],tat[10],time=0,count=0,end,smallest,ct[10];
 double avg_tat=0,avg_wt=0;
 printf("enter the number of processes\n");
 scanf("%d",&n);
 printf("enter the arrival time and burst time of the processes\n");
 for(int i=0;i<n;i++)
 {
  printf("P%d :",i+1);
  scanf("%d%d",&at[i],&bt[i]);
  temp[i]=bt[i];
 }
 bt[9]=9876;
 for(time=0;count!=n;time++)
 {
 smallest=9;
 for(int i=0;i<n;i++)
 {
  if(at[i]<=time && bt[i]<bt[smallest] && bt[i]>0)
  {
  smallest=i;
  }
 }if(smallest!=9);
  bt[smallest]--;
  if(bt[smallest]==0)
  {
  count++;
  end=time+1;
  ct[smallest]=end;
  tat[smallest]=end-at[smallest];
  wt[smallest]=end-at[smallest]-temp[smallest];
  }
  
 }
 printf("\n--------------------------------------------------------------\n");
 printf("P\tAT\tBT\tCT\tTAT\tWT\n");
 printf("----------------------------------------------------------------\n");
 for(int i=0;i<n;i++)
 {
  printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],temp[i],ct[i],tat[i],wt[i]);
  avg_tat += tat[i];
  avg_wt += wt[i];
 }
 printf("The average turnaround time is :%lf\n",avg_tat/n);
 printf("The average waiting time is: %lf",avg_wt/n);
}
