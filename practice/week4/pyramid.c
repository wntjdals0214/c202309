#include <stdio.h>

int main()
{
	int floor;
	printf("몇 층을 쌓겠습니까? (5~100)");
	scanf_s("%d", &floor); //층 수 입력

	for (int i = 0; i < floor; i++){
		for (int j = 0; j < floor - 1 - i; j++) {
			printf("s"); //위층부터 층 수 -1에서 1씩 줄여가며 s출력
		}
		for (int k = 0; k < i * 2 + 1; k++) {
			printf("*"); //위층부터 1부터 홀수개의 * 출력
		}
		printf("\n");
		}
	return 0;
}
