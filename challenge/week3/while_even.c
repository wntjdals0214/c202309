#include <stdio.h>

int main(void) {
	int i = 1;
	while (i < 10) {

		if (i % 2 == 0) {
			i++; // i�� ¦���� ��� 1 ���� Ȧ�� �����
			continue;
		}
		printf("%d Hello World!\n", i); // i�� HelloWorld! ���, i�� Ȧ��
		i++; // i�� 1 ���ϱ�
	}
	return 0;
}