#include <stdio.h>

int main(void) {
	int i = 1;
	do {
		printf("% d Hello World!\n", i);
		i++;
		//i�� ¦���̸� �ݺ��� ó������
		if (i % 2 == 0) {
			i++;
			continue;
		}
	} while (i < 10);
	return 0;
}