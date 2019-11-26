// 8번 - 프로세스 간 통신 / 파이프
// no8_pipe.c


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){

	int pid, n, fd[2];
	char buf[255];

	if(pipe(fd) < 0){
		perror("pipe error : ");
		exit(0);
	}

	if((pid = fork()) < 0){
		perror("fork error : ");
		exit(0);
	}
	else if(pid == 0){
		close(fd[0]);
		while(1){
			memset(buf, 0x00, 255);
			sprintf(buf, "Send to parent process. \n From child process pid(%d)\n", getpid());
			write(fd[1], buf, strlen(buf));
			sleep(1);
		}
	}
	else{
		close(fd[1]);
		memset(buf, 0x00, 255);
		n = read(fd[0], buf, 255);
		fprintf(stderr, "%s", buf);
	}
}
