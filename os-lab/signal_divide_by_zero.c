#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>


void fpe_handler(int sig){
	printf("causght signal (signal %d) divise by zero\n",sig);
	exit(sig);
}
int main(){
	signal(SIGINT,fpe_handler);

	int a,b;

	printf("Enter value of a : \n");
	scanf("%d",&a);

	printf("Enter value of b : \n");
        scanf("%d",&b);

	int c = a / b;

	printf("Result is %d \n",c);
	return 0;
}
