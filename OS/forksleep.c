//fork sleep
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
void main(){
	pid_t forkstatus;
	forkstatus = fork();
	if(forkstatus == 0){ /*child*/
		printf("The child is running \n");
		sleep(5);
		printf("The child is in sleep \n");
	}else if(forkstatus != -1){ /*parent*/
		printf("Parent is in wait \n");
		wait(NULL);
		printf("Parent is done \n");
	}else{
		perror("Error while executing!!");
	}
}

