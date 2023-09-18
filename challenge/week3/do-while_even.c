#include <stdio.h>

int main(void) {
	int i = 1;
	do {
		printf("% d Hello World!\n", i);
		i++;
		//i가 짝수이면 반복문 처음으로
		if (i % 2 == 0) {
			i++;
			continue;
		}
	} while (i < 10);
	return 0;
}