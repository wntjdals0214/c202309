#include <stdio.h>

int hapf(int value);

void main()
{
	printf("1���� 10������ ���� %d\n", hapf(10));
	printf("1���� 100������ ���� %d\n", hapf(100));
	printf("1���� 1000������ ���� %d\n", hapf(1000));
}

int hapf(int value)
{
	int i = 1;
	int hap = 0;

	while (i <= value) //i�� value��(10,100,1000)���� Ŀ���� ����
	{
		hap = hap + i; // hap(0)�� i��(1,2,3...)�� ��� ���Ѵ�
		i = i + 1; //i�� 1,2,3..���� 1�� ������Ŵ
	}
	return hap; //hap�� ���� main���� ��ȯ
}