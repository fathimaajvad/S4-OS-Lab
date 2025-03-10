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
 id=shmget((key_t)1222,1024,0666|IPC_CREAT);
 printf("Key of shared memory is: %d\n",id);
 sm=shmat(id,NULL,0);
 printf("the process attached at %p\n",sm);
 printf("enter the contents");
 read(0,buff,100);
 strcpy(sm,buff);
 printf("the data read from the memory\n%s\n",(char*)sm);
}
