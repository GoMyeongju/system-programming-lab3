//5번 - 프로세스 관련 함수 / 종료
//pc_stop.c

#include <stdio.h>
#include<sys/types.h>
#include <stdlib.h>

int main(){

	int exit_status;

	printf("enter exit status : ");
	scanf("%d", &exit_status);
	exit(exit_status);
}


