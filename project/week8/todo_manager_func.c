#include <stdio.h>
#define MAX_TASKS 10
#define CHAR_NUM 100
#include <string.h>
char tasks[MAX_TASKS][CHAR_NUM] = { "" }; // 100개의 문자를 저장할 수 있는 문자열 10개 목록(2차원 배열)
int taskCount = 0; // 할 일 개수
void addTask(char task[]); // 할 일 입력 함수
void delTask(int delIndex, int taskCount); // 할 일 삭제 함수
void printTask(int taskCount); // 할 일 목록 출력 함수
int main() {

	printf("TODO 리스트 시작! \n");

	while (1) {
		int choice = -1; // 사용자가 입력하는 번호 저장 변수

		// 메뉴 출력
		printf("------------------\n");
		printf("메뉴를 입력해주세요.\n");;
		printf("1. 할 일 추가\n2. 할 일 삭제\n3. 목록 보기\n4. 종료\n5.할 일 수정\n");
		printf("현재 할 일 수 = %d\n", taskCount);
		printf("------------------\n");
		scanf_s("%d", &choice);

		int terminate = 0; // 종료를 위한 변수
		int delIndex = -1; // case2(삭제)에서 사용할 변수
		int changeIndex = -1; // case5(수정)에서 사용할 변수
		char ch; // 할 일 수정시 버퍼를 받기 위한 변수


		switch (choice) {
		case 1: // 할 일 입력 블록
			addTask(tasks[taskCount]); // 할 일 입력 함수로 이동
			taskCount++; // 다음 문자열로 넘어가기 위해 +1, 1번 재입력시 다음 문자열에 입력됨
			break;
		case 2: // 할 일 삭제 블록
			printf("삭제할 할 일의 번호를 입력해주세요. (1부터 시작):");
			scanf_s("%d", &delIndex); // 입력한 번호를 변수에 저장
			if (delIndex > taskCount || delIndex <= 0) {
				printf("삭제 범위가 벗어났습니다.\n"); // 번호가 범위에 맞지 않을 때 알림
			}
			else {
				delTask(delIndex, taskCount); // 할 일 삭제 함수로 이동
				taskCount -= 1; // 삭제되어 빈 번호를 매우기 위해 뒤쪽 번호를 전부 1씩 낮춤
			}
			break;
		case 3: // 할 일 목록 출력 블록
			printf("할 일 목록\n");
			printTask(taskCount); // 할 일 목록 출력 함수로 이동
			printf("\n");
			break;
		case 4: // 종료 블록
			terminate = 1;
			break;
		case 5: // 할일 수정 블록
			printf("수정할 일의 번호를 입력해주세요. (1부터 시작):");
			scanf_s("%d", &changeIndex); // 입력한 번호를 변수에 저장
			if (changeIndex > taskCount || changeIndex <= 0) {
				printf("수정 범위가 벗어났습니다.\n"); // 번호가 범위에 맞지 않을 때 알림
			}
			else {
				printf("할 일을 입력하세요 (공백 없이 입력하세요):");
				scanf_s("%s", tasks[changeIndex - 1], (int)sizeof(tasks[changeIndex - 1]));
				// 2차원 배열에선 0부터 저장 되므로 입력받은 번호의 -1에 해당하는 문자열을 선택후 입력받은 할 일로 수정
				printf("%d. %s : 할 일을 수정합니다.\n", changeIndex, tasks[changeIndex - 1]);
			}
			break;
		default:
			printf("잘못된 선택입니다. 다시 선택하세요.\n"); // 1부터5가 아닌 숫자를 입력할 시 출력
		}

		if (terminate == 1) {
			printf("종료를 선택하셨습니다. 프로그램을 종료합니다.\n");
			break;
		}


		if (taskCount == 10) {
			printf("할 일이 다 찼습니다. 프로그램을 종료합니다.");
			terminate = 1; // 할 일이 10개가 될시 종료
			break;
		}
	}
}
// 할 일 입력 함수 설명
void addTask(char task[]) {
	printf("할 일을 입력하세요 (공백 없이 입력하세요): ");
	scanf_s("%s", tasks[taskCount], (int)sizeof(tasks[taskCount])); // 입력한 할 일을 tasks 2차원 배열의 문자열에 입력
	printf("할 일 ""%s""가 저장되었습니다\n\n", tasks[taskCount]);
}
// 할 일 삭제 함수 설명
void delTask(int delIndex, int taskCount) {
	printf("%d. %s : 할 일을 삭제합니다.\n", delIndex, tasks[delIndex - 1]);


	strcpy_s(tasks[delIndex - 1], sizeof(tasks[delIndex - 1]), "");
	// 2차원 배열에선 0부터 저장 되므로 입력받은 번호의 -1에 해당하는 문자열을 복사한 후 삭제

	for (int i = delIndex; i < taskCount + 1; i++) {
		strcpy_s(tasks[i - 1], sizeof(tasks[i]), tasks[i]);
	}
}
// 할 일 목록 출력 함수 설명
void printTask(int taskCount) {
	for (int i = 0; i < taskCount; i++) {
		printf("%d. %s \n", i + 1, tasks[i]); // 할 일의 목록을 쭉 출력
	}
}