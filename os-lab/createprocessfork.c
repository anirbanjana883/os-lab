#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	fork();

	int pid = getpid();
	int ppid = getppid();

	printf("New process created\n");
    	printf("Process ID (PID): %d\n", pid);
    	printf("Parent Process ID (PPID): %d\n\n", ppid);

	return 0;
}
