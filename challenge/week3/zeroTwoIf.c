#include <stdio.h>

int main() {
    // ���� ����
	int num = 0;
	printf("���ڸ� �Է��Ͻÿ�: ");
	scanf_s("%d", &num); // �Է¹��� ���� ������ ����

	if (num == 0) {
		printf("zero"); // �Է��� 0�̶�� �ش� ������ ����Ѵ�.
	}
	else if (num == 1) {
		printf("one"); // �Է��� 1�̶�� �ش� ������ ����Ѵ�.
	}
	else if (num == 2) {
		printf("two"); // �Է��� 2�̶�� �ش� ������ ����Ѵ�.
	}
	else {
		printf("not 0~2"); // �Է��� 0~2�� �ƴ϶�� �ش� ������ ����Ѵ�.
	}
	return 0;
}