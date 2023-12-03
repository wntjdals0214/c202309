#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StudentInfo {
	char* name;
	int score;
};

void initializeStudentInfo(struct StudentInfo* student);

void classifyStudents(const struct StudentInfo* student, char targetGrade) { //성적 등급 함수
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
		grade = 'F'; //점수에 따라 등급 부여
	}
	if (targetGrade == grade) {
		printf("%s 학생은 %c 점수를 받았습니다.\n", student->name, targetGrade); //학생 등급 출력
	}
}

int sumScores(const struct StudentInfo* student) { // 점수 총합 함수
	int score;
	score = student->score;
	return score;
}

double averageScores(sum, numStudents) { // 점수 평균 함수
	double average;
	average = (double) sum / (double) numStudents;
	return average;
}

int printRanks(int score1, const struct StudentInfo* student, int a) { //점수 순위 함수
	int q = student->score;
	if (score1 < q) {
		a += 1;
	}
	else {
		a = a; //1번 학생의 점수를 5명 전부와 비교하며 점수가 더 작을 경우 a의 값을 증가시킴
	}
	return a;
}

int main() {
	int numStudents;

	// 사용자로부터 학생 수 입력 받기
	printf("학생 수를 입력하세요: ");
	scanf_s("%d", &numStudents);

	//구조체 포인터를 사용하여 동적으로 배열 할당
	struct StudentInfo* students = (struct StudentInfo*)malloc(numStudents * sizeof(struct StudentInfo));

	if (students == NULL) {
		return 1;
	}

	// 각 구조체에 값을 입력
	for (int i = 0; i < numStudents; i++) {
		initializeStudentInfo(&students[i], i);
	}

	int sum = 0;
	int score;
	char target;
	printf("특정 점수 (A,B,C,D,F)를 입력하시오:\n"); //원하는 등급 입력
	scanf_s(" %c", &target, 1);
	printf("학생 성적 분류:\n");
	for (int i = 0; i < numStudents; i++) {
		classifyStudents(&students[i], target); // 함수 실행
		score = sumScores(&students[i]); // 함수 실행
		sum += score;
	}
	double average = averageScores(sum, numStudents); // 함수 실행
	printf("학생들 점수의 총 합은 %d 이고, 평균 값은 %lf 입니다.\n", sum, average);
	for (int i = 0; i < numStudents; i++) {
		int a = 0;
		int rank;
		for (int j = 0; j < numStudents; j++) {
			rank = printRanks(students[i].score, &students[j], a);
			a = rank;
		}
		printf("%s 학생의 순위는 %d 입니다.\n", students[i].name, rank + 1);
		
	}

	return 0;
}

// 구조체 초기화 함수
void initializeStudentInfo(struct StudentInfo* student, int i) {
	// 이름을 입력받아 동적으로 메모리 할당
	printf("학생 %d의 이름을 입력하세요: ", i + 1);
	char temp[100];
	scanf_s("%s", temp, (int)sizeof(temp));
	student->name = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy_s(student->name, strlen(temp) + 1, temp);

	// 성적을 입력받아 동적으로 메모리 할당
	printf("학생 %d의 성적을 입력하세요: ", i + 1);
	scanf_s("%d", &student->score);
}
