#include <stdio.h>

int hapf(int value);

void main()
{
	printf("1부터 10까지의 합은 %d\n", hapf(10));
	printf("1부터 100까지의 합은 %d\n", hapf(100));
	printf("1부터 1000까지의 합은 %d\n", hapf(1000));
}

int hapf(int value)
{
	int i = 1;
	int hap = 0;

	while (i <= value) //i가 value값(10,100,1000)보다 커지면 중지
	{
		hap = hap + i; // hap(0)에 i값(1,2,3...)을 계속 더한다
		i = i + 1; //i를 1,2,3..으로 1씩 증가시킴
	}
	return hap; //hap의 값을 main으로 반환
}