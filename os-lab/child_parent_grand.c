#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	pid_t pid;

	pid = fork();

	if(pid < 0){
		printf("Process cration failed\n");
		
	}else if(pid == 0){
		printf("child porcess \n");
		 printf("child porcess id %d \n",getpid());
		  printf("parent porcess id %d \n",getppid());
		  
	}else{
                printf("parent porcess \n");
                 printf("parent porcess id %d \n",getpid());
		  printf("child porcess id %d \n",pid);
                  printf("Grandparent porcess id %d \n",getppid());
                  
        }
	return 0;
}
