#include <stdio.h>
#define STUDENTS 5

void classifyStudents(int *scores, char targetGrade) { //���� ��� �Լ�
	printf("�л� ���� �з�:\n");
	char grade = ' ';
	int* p = scores;
	for (int i = 0; i < STUDENTS; i++) {
		if (*p >= 90) {
			grade = 'A';
		}
		else if (*p >= 80) {
			grade = 'B';
		}
		else if (*p >= 70) {
			grade = 'C';
		}
		else if (*p >= 60) {
			grade = 'D';
		}
		else {
			grade = 'F'; //������ ���� ��� �ο�
		}
		if (targetGrade == grade) {
			printf("%d �л��� %c ������ �޾ҽ��ϴ�.", i + 1, targetGrade); //�л� ��� ���
		}
		p++;
	}
}

int sumScores(int *scores) { //���� ���� �Լ�
	int sum = 0;
	int* p = scores;
	for (int i = 0; i < STUDENTS; i++) {
		sum += *p;
		p++;
	}
	return sum;
}

double averageScores(int *scores) { //���� ��� �Լ�
	int sum = 0;
	int* p = scores;
	for (int i = 0; i < STUDENTS; i++) {
		sum += *p;
		p++;
	}
	double average;
	average = sum / STUDENTS;
	return average;
}

void printRanks(int *scores) { //���� ���� �Լ�
	int* p = scores;
	for (int i = 0; i < STUDENTS; i++) {
		int a = 0;
		int* q = scores;
		for (int j = 0; j < STUDENTS; j++) {
			if (*p < *q) {
				a += 1;
			}
			else {
				a = a; //1�� �л��� ������ 5�� ���ο� ���ϸ� ������ �� ���� ��� a�� ���� ������Ŵ
			}
			q++;
		} //a���� ���� ������ ����
		if (a == 0) {
			printf("%d �л��� ������ 1 �Դϴ�.\n", i + 1);
		}
		else if (a == 1) {
			printf("%d �л��� ������ 2 �Դϴ�.\n", i + 1);
		}
		else if (a == 2) {
			printf("%d �л��� ������ 3 �Դϴ�.\n", i + 1);
		}
		else if (a == 3) {
			printf("%d �л��� ������ 4 �Դϴ�.\n", i + 1);
		}
		else if (a == 4) {
			printf("%d �л��� ������ 5 �Դϴ�.\n", i + 1);
		}
		p++;
	}
}

int main() {
	int scores[STUDENTS];

	for (int i = 0; i < STUDENTS; i++) {
		printf("�л� %d�� ������ �Է��ϼ���: ", i + 1);
		scanf_s("%d", &scores[i]); //�л� ���� �迭�� �Է�
	}

	char ch = getchar(); //���� �ӽ� ���� ����, ��������� ����

	char target;
	printf("Ư�� ���� (A,B,C,D,F)�� �Է��Ͻÿ�: "); //���ϴ� ��� �Է�
	scanf_s("%c", &target, 1);

	classifyStudents(scores, target); // �Լ� ����

	int sum = sumScores(scores); // �Լ� ����
	double average = averageScores(scores); // �Լ� ����
	printf("�л��� ������ �� ���� %d �̰�, ��� ���� %lf �Դϴ�.\n", sum, average);

	printRanks(scores);

	return 0;
}