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

	return 0;
}