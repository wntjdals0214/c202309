#include <stdio.h>

int main(void) {
	int i = 1;
	do {
		printf("% d Hello World!\n", i); // i�� HelloWorld! ���, i�� Ȧ��
		i++;
		// i�� 1 ���ϱ� 
		if (i % 2 == 0) {
			i++; // i�� ¦���� ��� 1 ���� Ȧ�� �����
			continue;
		}
	} while (i < 10);
	return 0;
}