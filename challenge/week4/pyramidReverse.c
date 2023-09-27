#include <stdio.h>

int main()
{
	int floor;
	printf("몇 층을 쌓겠습니까? (5~100)"); //층 수 정하기
	scanf_s("%d", &floor);

	for (int i = floor; i > 0; i--) { // i를 층 수 부터 1씩 작아지도록
		for (int j = 0; j < floor - i; j++) { // 층 수 - i로 s가 1씩 증가하도록
		printf("s");
	}
		for (int k = 0; k < 2 * i - 1; k++) { // 2*i-1로 층 수마다 *가 2씩 작아지도록
			printf("*");
		}
		printf("\n");
	}
	return 0;
}