// 9번 - 메시지 큐 채팅(서버)
// no9_server.c


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <mqueue.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]){

	struct mq_attr q_attr;
	q_attr.mq_maxmsg = 10;
	q_attr.mq_msgsize = 4;

	char msg[10];

	mqd_t mfd;

	
	mfd = mq_open("/no9_test", O_RDWR | O_CREAT, 0600, &q_attr);

	if(mfd == -1){
		perror("open error");
		exit(0);
	}
	if((mq_receive(mfd, msg, q_attr. mq_msgsize, NULL)) == -1){
		exit(-1);
	}
	
	printf("Client msg : %s\n", msg);
	printf("* * * Close * * *\n");
}


