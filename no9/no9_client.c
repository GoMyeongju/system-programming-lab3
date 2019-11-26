// 9번 - 메시지큐 채팅(클라이언트)
// no9_client.c


#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <string.h>

int main(int argc, char *argv[]){

	struct mq_attr q_attr;
	q_attr.mq_maxmsg = 10;
	q_attr.mq_msgsize = 4;
	char msg[30];
	int stat;
	mqd_t mfd;

	mfd = mq_open("/no9_test", O_WRONLY, 0666, &q_attr);

	if(mfd == -1){
		perror("open error");
		exit(1);
	}

	printf("write your message : ");
	scanf("%[^\n]s", msg);
	int len;
	len = strlen(msg);
	msg[len] = '\0';

	if((mq_send(mfd, msg, q_attr.mq_msgsize,1)) == -1){
		perror("send error");
		exit(-1);
	}

	printf("* * * Close * * *\n");
}
