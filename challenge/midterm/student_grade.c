#include <stdio.h>
#define STUDENTS 5
#define SUBJECTS 3
#define CHARNUM 20
void printStudentResults(double studentScores[STUDENTS][SUBJECTS], char studentNames[STUDENTS][CHARNUM]);
void printSubjectResults(double studentScores[STUDENTS][SUBJECTS], char subjectNames[SUBJECTS][CHARNUM]);
int main() {
	char subjectNames[SUBJECTS][CHARNUM] = { "퀴즈", "중간고사", "기말고사" };
	char studentNames[STUDENTS][CHARNUM] = { "" }; // 학생 이름이 저장될 배열
	double studentScores[STUDENTS][SUBJECTS] = { 0.0 }; // 학생의 시험 별 성적이 점수가 저장될 배열
	printf("학생 %d명의 이름의 입력을 시작합니다. \n", STUDENTS);
	// TODO 1.1: 학생 이름을 입력받는 코드 블록 작성
	for (int i = 0; i < STUDENTS; i++) {
		printf("%d번째 학생의 이름을 입력하세요: ", i+1);
		scanf_s("%s", studentNames[i], (int)sizeof(studentNames[i])); // 배열 0번 부터 끝까지 이름 저장
	}
	// 입력된 학생 이름이 잘 저장되었는지 확인하는 코드 블록
	printf("학생 이름이 모두 입력되었습니다. \n");
	printf("입력된 학생 이름은 다음과 같습니다. \n");
	for (int i = 0; i < STUDENTS; i++) {
		printf("%s", studentNames[i]);
		if (i != STUDENTS - 1) {
			printf(", "); // 배열에 저장된 이름을 출력
		}
	}
	printf("\n");
	printf("--------------------\n");
	printf("각 학생의 %s, %s, %s 점수를 차례대로 입력해주세요. (띄어쓰기 구분)\n ", subjectNames[0], subjectNames[1], subjectNames[2]);

	// TODO 1.2: 학생들의 시험 별 점수를 입력받는 코드 블록 작성
	for (int i = 0; i < STUDENTS; i++) {
		printf("%s의 성적: ", studentNames[i]);
		scanf_s("%lf %lf %lf", &studentScores[i][0], &studentScores[i][1], &studentScores[i][2]);
	}

	printf("학생들의 시험 점수가 모두 입력 되었습니다.\n");
	printf("--------------------\n");
	printf("학생 별 성적은 다음과 같습니다 \n");
	
	printStudentResults(studentScores, studentNames);

	printf("--------------------\n");
	printf("과목 별 평균 점수는 아래와 같습니다. \n");

	printSubjectResults(studentScores, subjectNames);

	return 0;
}
// 학생별 성적 평균 계산
void printStudentResults(double studentScores[STUDENTS][SUBJECTS], char studentNames[STUDENTS][CHARNUM]) {
	for (int i = 0; i < STUDENTS; i++) {
		double totalScores = 0;
		double finalScore;
		for (int j = 0; j < SUBJECTS; j++) {
			totalScores += studentScores[i][j]; // 배열에서 학생을 고정하고 과목들 바꾸며 총 점수에 더함
		}
		finalScore = totalScores / SUBJECTS; // 과목수로 나눠 학생별 평균 구하기
		printf("\t%s의 평균 점수: %.2lf\n", studentNames[i], finalScore);
	}
}
// 과목별 성적 평균 계산
void printSubjectResults(double studentScores[STUDENTS][SUBJECTS], char subjectNames[SUBJECTS][CHARNUM]) {
	for (int i = 0; i < SUBJECTS; i++) {
		double totalScores = 0;
		double subjectScore;
		for (int j = 0; j < STUDENTS; j++) {
			totalScores += studentScores[j][i]; // 배열에서 과목을 고정하고 학생을 바꾸며 총 점수에 더함
		}
		subjectScore = totalScores / STUDENTS; // 학생수로 나눠 과목별 평균 구하기
		printf("\t%s의 평균 점수는 %.2lf 입니다.\n", subjectNames[i], subjectScore);
	}
}