#include <stdio.h>

int main() {
	//2차원 배열로 구구단 저장
	int gugudan[9][9];

	//구구단 계산 및 저장
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			gugudan[i][j] = (i + 1) * (j + 1);
		}
	}
	printf("gugudan 배열에 저장 완료!\n");

	int dan;
	int bae;

	//사용자 입력 받기
	printf("몇 단을 출력할까요? (2 에서 9 사이): ");
	scanf_s("%d", &dan);
	printf("몇 배를 할까요? (2 에서 9 사이): ");
	scanf_s("%d", &bae);

	//입력한 숫자에 해당하는 구구단 출력
	if (dan >= 2 && dan <= 9) {
		printf("%d배를 한 %d단을 출력합니다:\n", bae, dan);
		printf("%d x %d = %d\n", dan, bae, gugudan[dan - 1][bae - 1]);
	}
	else {
		printf("잘못된 입력입니다. 2에서 9 사이의 숫자를 입력하세요,\n");
	}

	return 0;
}