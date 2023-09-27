#include <stdio.h>

int main()
{
	int floor;
	printf("¸î ÃþÀ» ½×°Ú½À´Ï±î? (5~100)");
	scanf_s("%d", &floor);

	for (int i = floor; i > 0; i--) {
		for (int j = 0; j < floor - i; j++) {
		printf("s");
	}
		for (int k = 0; k < 2 * i - 1; k++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}