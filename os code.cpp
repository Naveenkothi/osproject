#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;

int  main()
{
  char a[10][5],temp[5];
  int m,l,priorityTime[10],waitingTime[10],tAt=0,pr[10],temp1,n;
  float average_waiting_time;
 printf("enter no of processes:");
 scanf("%d",&n);
  for(m=0;m<n;m++)
  {
  printf("enter process%d name:",m+1);
 scanf("%s",&a[m]);
  printf("enter process time:");
 scanf("%d",&priorityTime[m]);
  printf("enter priority:");
  scanf("%d",&pr[m]);
  }
 for(m=0;m<n-1;m++)
 {
 for(l=m+1;l<n;l++)
 {
   if(pr[m]>pr[l])
 {
   temp1=pr[m];
 pr[m]=pr[l];
  pr[l]=temp1;
  temp1=priorityTime[m];
  priorityTime[m]=priorityTime[l];
  priorityTime[l]=temp1;
 strcpy(temp,a[m]);
 strcpy(a[m],a[l]);
  strcpy(a[l],temp);
  }
  }
  }
 waitingTime[0]=0;
  for(m=1;m<n;m++)
  {
   waitingTime[m]=waitingTime[m-1] + priorityTime[m-1];
   tAt=tAt+waitingTime[m];
   }  
average_waiting_time=(float)tAt/n;  
printf("p_name\t p_time\t priority\t w_time\n");
for(m=0;m<n;m++)  
{
   printf(" %s\t %d\t %d\t %d\n" ,a[m],priorityTime[m],pr[m],waitingTime[m]);
   }
  printf("Turn Around Time =%d\n avg waiting time=%f",tAt,average_waiting_time);
   }
