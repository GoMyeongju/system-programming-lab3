//5번 - 프로세스 관련 함수 / 프로세스 생성
//pc_start.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	
	pid_t pid;
	printf("Calling fork \n");

	pid = fork();
	if(pid == 0){
		printf("I'm child process\n");
	}else if(pid > 0){
		printf("I'm parent process\n");
		wait((int*)0);
	}
	else
		perror("fork failed : ");
}


