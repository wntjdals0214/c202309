#include <stdio.h>

int main() {
	//2���� �迭�� ������ ����
	int gugudan[9][9];

	//������ ��� �� ����
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			gugudan[i][j] = (i + 1) * (j + 1);
		}
	}
	printf("gugudan �迭�� ���� �Ϸ�!\n");

	int dan;
	int bae;

	//����� �Է� �ޱ�
	printf("�� ���� ����ұ��? (2 ���� 9 ����): ");
	scanf_s("%d", &dan);
	printf("�� �踦 �ұ��? (2 ���� 9 ����): ");
	scanf_s("%d", &bae);

	//�Է��� ���ڿ� �ش��ϴ� ������ ���
	if (dan >= 2 && dan <= 9) {
		printf("%d�踦 �� %d���� ����մϴ�:\n", bae, dan);
		printf("%d x %d = %d\n", dan, bae, gugudan[dan - 1][bae - 1]);
	}
	else {
		printf("�߸��� �Է��Դϴ�. 2���� 9 ������ ���ڸ� �Է��ϼ���,\n");
	}

	return 0;
}