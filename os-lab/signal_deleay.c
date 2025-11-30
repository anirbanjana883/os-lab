#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void handler(int sig){
	printf("parent received signal %d from child \n",sig);
}
int main(){
	signal(SIGUSR1,handler);
	pid_t pid = fork();

	if(pid == 0){
		printf("Child process \n");
		sleep(5);
		kill(getppid(),SIGUSR1);
	}else if(pid > 0){
		printf("Parent process \n");
		printf("paremt is waiting .....\n");
		while(1){
			sleep(1);
		}
	}
	return 0;
}
