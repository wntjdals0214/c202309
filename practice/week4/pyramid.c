#include <stdio.h>

int main()
{
	int floor;
	printf("�� ���� �װڽ��ϱ�? (5~100)");
	scanf_s("%d", &floor); //�� �� �Է�

	for (int i = 0; i < floor; i++){
		for (int j = 0; j < floor - 1 - i; j++) {
			printf("s"); //�������� �� �� -1���� 1�� �ٿ����� s���
		}
		for (int k = 0; k < i * 2 + 1; k++) {
			printf("*"); //�������� 1���� Ȧ������ * ���
		}
		printf("\n");
		}
	return 0;
}
