#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StudentInfo {
	char* name;
	int score;
};

void initializeStudentInfo(struct StudentInfo* student);

void classifyStudents(const struct StudentInfo* student, char targetGrade) { //���� ��� �Լ�
	char grade = ' ';
	 
	if (student->score >= 90) {
		grade = 'A';
	}
	else if (student->score >= 80) {
		grade = 'B';
	}
	else if (student->score >= 70) {
		grade = 'C';
	}
	else if (student->score >= 60) {
		grade = 'D';
	}
	else {
		grade = 'F'; //������ ���� ��� �ο�
	}
	if (targetGrade == grade) {
		printf("%s �л��� %c ������ �޾ҽ��ϴ�.\n", student->name, targetGrade); //�л� ��� ���
	}
}

int sumScores(const struct StudentInfo* student) { // ���� ���� �Լ�
	int score;
	score = student->score;
	return score;
}

double averageScores(sum, numStudents) { // ���� ��� �Լ�
	double average;
	average = (double) sum / (double) numStudents;
	return average;
}

int printRanks(int score1, const struct StudentInfo* student, int a) { //���� ���� �Լ�
	int q = student->score;
	if (score1 < q) {
		a += 1;
	}
	else {
		a = a; //1�� �л��� ������ 5�� ���ο� ���ϸ� ������ �� ���� ��� a�� ���� ������Ŵ
	}
	return a;
}

int main() {
	int numStudents;

	// ����ڷκ��� �л� �� �Է� �ޱ�
	printf("�л� ���� �Է��ϼ���: ");
	scanf_s("%d", &numStudents);

	//����ü �����͸� ����Ͽ� �������� �迭 �Ҵ�
	struct StudentInfo* students = (struct StudentInfo*)malloc(numStudents * sizeof(struct StudentInfo));

	if (students == NULL) {
		return 1;
	}

	// �� ����ü�� ���� �Է�
	for (int i = 0; i < numStudents; i++) {
		initializeStudentInfo(&students[i], i);
	}

	int sum = 0;
	int score;
	char target;
	printf("Ư�� ���� (A,B,C,D,F)�� �Է��Ͻÿ�:\n"); //���ϴ� ��� �Է�
	scanf_s(" %c", &target, 1);
	printf("�л� ���� �з�:\n");
	for (int i = 0; i < numStudents; i++) {
		classifyStudents(&students[i], target); // �Լ� ����
		score = sumScores(&students[i]); // �Լ� ����
		sum += score;
	}
	double average = averageScores(sum, numStudents); // �Լ� ����
	printf("�л��� ������ �� ���� %d �̰�, ��� ���� %lf �Դϴ�.\n", sum, average);
	for (int i = 0; i < numStudents; i++) {
		int a = 0;
		int rank;
		for (int j = 0; j < numStudents; j++) {
			rank = printRanks(students[i].score, &students[j], a);
			a = rank;
		}
		printf("%s �л��� ������ %d �Դϴ�.\n", students[i].name, rank + 1);
		
	}

	return 0;
}

// ����ü �ʱ�ȭ �Լ�
void initializeStudentInfo(struct StudentInfo* student, int i) {
	// �̸��� �Է¹޾� �������� �޸� �Ҵ�
	printf("�л� %d�� �̸��� �Է��ϼ���: ", i + 1);
	char temp[100];
	scanf_s("%s", temp, (int)sizeof(temp));
	student->name = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy_s(student->name, strlen(temp) + 1, temp);

	// ������ �Է¹޾� �������� �޸� �Ҵ�
	printf("�л� %d�� ������ �Է��ϼ���: ", i + 1);
	scanf_s("%d", &student->score);
}
