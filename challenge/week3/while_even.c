#include <stdio.h>

int main(void) {
	int i = 1;
	while (i < 10) {
		//i�� ¦���̸� �ݺ��� ó������
		if (i % 2 == 0) {
			i++;
			continue;
		}
		printf("%d Hello World!\n", i);
		i++;
	}
	return 0;
}