#include <stdio.h>

int main() {
    // 변수 생성
	int num = 0;
	printf("숫자를 입력하시오: ");
	scanf_s("%d", &num); // 입력받은 수를 변수에 저장

	if (num == 0) {
		printf("zero"); // 입력이 0이라면 해당 문장을 출력한다.
	}
	else if (num == 1) {
		printf("one"); // 입력이 1이라면 해당 문장을 출력한다.
	}
	else if (num == 2) {
		printf("two"); // 입력이 2이라면 해당 문장을 출력한다.
	}
	else {
		printf("not 0~2"); // 입력이 0~2가 아니라면 해당 문장을 출력한다.
	}
	return 0;
}