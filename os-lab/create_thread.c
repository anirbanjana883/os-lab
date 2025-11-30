#include<stdio.h>
#include<pthread.h>

void *msg(){
	printf("welcome form thread1......... \n");
	return NULL;
}

int main(){

	pthread_t t;
	pthread_create(&t,NULL,msg,NULL);
	pthread_join(t,NULL);

	printf("main thread finished......... \n");
	return 0;
}
