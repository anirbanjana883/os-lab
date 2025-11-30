#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void signalhandeler(int sig){
	printf("caught signal %d \n",sig);
	exit(sig);
}
int main(){
	signal(SIGINT,signalhandeler);

	while(1){
		printf("Hello World \n");
	}
	return 0;
}
