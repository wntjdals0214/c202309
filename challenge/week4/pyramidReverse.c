#include <stdio.h>

int main()
{
	int floor;
	printf("�� ���� �װڽ��ϱ�? (5~100)"); //�� �� ���ϱ�
	scanf_s("%d", &floor);

	for (int i = floor; i > 0; i--) { // i�� �� �� ���� 1�� �۾�������
		for (int j = 0; j < floor - i; j++) { // �� �� - i�� s�� 1�� �����ϵ���
		printf("s");
	}
		for (int k = 0; k < 2 * i - 1; k++) { // 2*i-1�� �� ������ *�� 2�� �۾�������
			printf("*");
		}
		printf("\n");
	}
	return 0;
}