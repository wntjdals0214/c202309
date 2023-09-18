#include <stdio.h>

int main(void) {
	int i = 1;
	while (i < 10) {
		//i가 짝수이면 반복문 처음으로
		if (i % 2 == 0) {
			i++;
			continue;
		}
		printf("%d Hello World!\n", i);
		i++;
	}
	return 0;
}