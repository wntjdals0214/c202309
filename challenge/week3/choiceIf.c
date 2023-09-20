#include <stdio.h>

int main() {
	// 변수 생성
	int choice;

	printf("1. 파일 저장 \n");
	printf("2. 저장 없이 닫기 \n");
	printf("3. 종료 \n");
	scanf_s("%d", &choice); // 입력받은 수를 변수에 저장

	if (choice == 1) {
		printf("파일을 저장합니다."); // 입력이 1이라면 해당 문장을 출력한다.
	}
	else if (choice == 2) {
		printf("저장 없이 닫습니다."); // 입력이 2이라면 해당 문장을 출력한다.
	}
	else if (choice == 3) {
		printf("종료합니다."); // 입력이 3이라면 해당 문장을 출력한다.
	}
	else {
		printf("잘못 입력하셨습니다."); // 입력이 1~3이 아니라면 해당 문장을 출력한다.
	}

	return 0;
}