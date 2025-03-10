#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
 int id;
 void *sm;
 char buff[100];
 id=shmget((key_t)1222,1024,0666);
 printf("The id of processes is: %d",id);
 sm=shmat(id,NULL,0);
 printf("the process attached at %p",sm);
 printf("the data read from memory\n%s\n",(char *)sm);
 strcpy(buff,sm);
 int a=buff[0]-'0';
 int b=buff[2]-'0';
 printf("the sum is %d",a+b);
 
}
