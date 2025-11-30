#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig){
	printf("child got signal %d from parent \n",sig);
	exit(sig);
}

int main(){

	signal(SIGUSR1,handler);
	pid_t pid = fork();

	if(pid < 0){
		printf("failed\n");
		exit(1);
	}else if (pid == 0){
		printf("Waiting for parnet signal\n");
		while(1){
			sleep(1);
		}
	}else{
		printf("parent will sent signal after 3 sec\n");
		sleep(3);
		kill(pid,SIGUSR1);
		printf("signal sent successfully");
	}
	return 0;
}
