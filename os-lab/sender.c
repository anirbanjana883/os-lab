#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>

struct msgbuf{
	long mtype;
	char mtext[100];
};

int main(){
	struct msgbuf message;
	int mqid = msgget((key_t)15,IPC_CREAT|0666);

	if(mqid < 0){
		printf("Message creation failed \n");
	}

	fgets(message.mtext,sizeof(message.mtext),stdin);

	message.mtype = 1;

	int len = strlen(message.mtext) + 1;

	if(msgsnd(mqid,&message,len,0) == -1){
		printf("Message sent failed\n");
	}

	printf("Message sent successfully \n");
	return 0;
}
