#include <stdio.h>

int main(void) {
	int i = 1;
	do {
		printf("% d Hello World!\n", i); // i와 HelloWorld! 출력, i는 홀수
		i++;
		// i에 1 더하기 
		if (i % 2 == 0) {
			i++; // i가 짝수일 경우 1 더해 홀수 만들기
			continue;
		}
	} while (i < 10);
	return 0;
}