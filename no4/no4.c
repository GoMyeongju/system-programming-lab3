// 4번 - 타자연습 프로그램
// no4.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){

	time_t start_t, end_t;
	float result;
	char text[3][30] = {{"Hello, Welecome."}, 
		{"My name is Myeongju"}, 
		{"Nice to meet you"}};

	char input[3][30];

	system("clear");

	int text_len, input_len, longer_len, total, chk=0;
	char c;

	start_t = time(NULL);

	for(int i =0; i < 3; i++){
		puts(text[i]);
		scanf("%[^\n]s", input[i]);
		text_len = strlen(text[i]);
		input_len = strlen(input[i]);

		printf("글자 수 : %d | 내가 입력한 글자 수 : %d\n", text_len, input_len);

		total = input_len;

		if(text_len > input_len) longer_len = text_len;
		else if(text_len <=  input_len) longer_len = input_len;

		for(int j =0; j < longer_len; j++){
			if(text[i][j] != input[i][j]) chk++;
		}

		printf("오타 수 : %d\n", chk);
		chk = 0;
		printf("엔터를 누르면 넘어갑니다!  \n\n\n");
		getchar();
	}

	end_t = time(NULL);
	result = (float)(end_t - start_t);
	printf("평균 입력 시간 : %0.2f초\n", result/3);
	printf("분당 타자 수 : %0.2f타 \n", (60/result)*total);
}

