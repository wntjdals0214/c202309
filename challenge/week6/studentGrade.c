#include <stdio.h>
#define STUDENTS 5

void classifyStudents(int scores[], char targetGrade) { //성적 등급 함수
	printf("학생 성적 분류:\n");
	char grade = ' ';
	for (int i = 0; i < STUDENTS; i++) {
		if (scores[i] >= 90) {
			grade = 'A';
		}
		else if (scores[i] >= 80) {
			grade = 'B';
		}
		else if (scores[i] >= 70) {
			grade = 'C';
		}
		else if (scores[i] >= 60) {
			grade = 'D';
		}
		else {
			grade = 'F'; //점수에 따라 등급 부여
		}
		if (targetGrade == grade) {
			printf("%d 학생은 %c 점수를 받았습니다.", i + 1, targetGrade); //학생 등급 출력
		}
	}
}

int sumScores(int scores[]) { //점수 총합 함수
	int sum = 0;

	for (int i = 0; i < STUDENTS; i++) {
		sum += scores[i];
	}
	return sum;
}

double averageScores(int scores[]) { //점수 평균 함수
	int sum = 0;
	for (int i = 0; i < STUDENTS; i++) {
		sum += scores[i];
	}
	double average;
	average = sum / STUDENTS;
	return average;
}

void printRanks(int scores[]) { //점수 순위 함수

	for (int i = 0; i < STUDENTS; i++) {
		int a = 0;
		for (int j = 0; j < STUDENTS; j++) {
			if (scores[i] < scores[j]) {
				a += 1;
			}
			else {
				a = a; //1번 학생의 점수를 5명 전부와 비교하며 점수가 더 작을 경우 a의 값을 증가시킴
			}
		} //a값에 따라 순위를 결정
		if (a == 0) {
			printf("%d 학생의 순위는 1 입니다.\n", i + 1);
		}
		else if (a == 1) {
			printf("%d 학생의 순위는 2 입니다.\n", i + 1);
		}
		else if (a == 2) {
			printf("%d 학생의 순위는 3 입니다.\n", i + 1);
		}
		else if (a == 3) {
			printf("%d 학생의 순위는 4 입니다.\n", i + 1);
		}
		else if (a == 4) {
			printf("%d 학생의 순위는 5 입니다.\n", i + 1);
		}
	}
}

int main() {
	int scores[STUDENTS];

	for (int i = 0; i < STUDENTS; i++) {
		printf("학생 %d의 성적을 입력하세요: ", i + 1);
		scanf_s("%d", &scores[i]); //학생 점수 배열에 입력
	}

	char ch = getchar(); //버퍼 임시 저장 변수, 엔터지우기 위해

	char target;
	printf("특정 점수 (A,B,C,D,F)를 입력하시오: "); //원하는 등급 입력
	scanf_s("%c", &target, 1);

	classifyStudents(scores, target); // 함수 실행

	int sum = sumScores(scores); // 함수 실행
	double average = averageScores(scores); // 함수 실행
	printf("학생들 점수의 총 합은 %d 이고, 평균 값은 %lf 입니다.\n",sum,average);

	printRanks(scores);

	return 0;
}