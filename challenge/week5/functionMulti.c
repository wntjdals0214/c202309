#include <stdio.h>

long multif(long value);

int main()
{
	printf("1부터 2까지의 곱은 %ld\n", multif(2));
	printf("1부터 3까지의 곱은 %ld\n", multif(3));
	printf("1부터 5까지의 곱은 %ld\n", multif(5));
}

long multif(long value)
{
	long i = 1;
	long multi = 1;

	while (i <= value) //i가 value값(2,3,5)보다 커지면 중지
	{
		multi = multi * i; //multi(1)에 i값(1,2,3...)을 계속 곱한다
		i = i + 1; //i를 1,2,3..으로 1씩 증가시킴
	}
	return multi; //multi의 값을 main으로 반환

	return 0;
}