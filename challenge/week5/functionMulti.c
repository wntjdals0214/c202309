#include <stdio.h>

long multif(long value);

int main()
{
	printf("1���� 2������ ���� %ld\n", multif(2));
	printf("1���� 3������ ���� %ld\n", multif(3));
	printf("1���� 5������ ���� %ld\n", multif(5));
}

long multif(long value)
{
	long i = 1;
	long multi = 1;

	while (i <= value) //i�� value��(2,3,5)���� Ŀ���� ����
	{
		multi = multi * i; //multi(1)�� i��(1,2,3...)�� ��� ���Ѵ�
		i = i + 1; //i�� 1,2,3..���� 1�� ������Ŵ
	}
	return multi; //multi�� ���� main���� ��ȯ

	return 0;
}