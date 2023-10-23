#include <stdio.h>
#define MAX_TASKS 10
#define CHAR_NUM 100
#include <string.h>
char tasks[MAX_TASKS][CHAR_NUM] = { "" }; // 100���� ���ڸ� ������ �� �ִ� ���ڿ� 10�� ���(2���� �迭)
int taskCount = 0; // �� �� ����
void addTask(char task[]); // �� �� �Է� �Լ�
void delTask(int delIndex, int taskCount); // �� �� ���� �Լ�
void printTask(int taskCount); // �� �� ��� ��� �Լ�
int main() {

	printf("TODO ����Ʈ ����! \n");

	while (1) {
		int choice = -1; // ����ڰ� �Է��ϴ� ��ȣ ���� ����

		// �޴� ���
		printf("------------------\n");
		printf("�޴��� �Է����ּ���.\n");;
		printf("1. �� �� �߰�\n2. �� �� ����\n3. ��� ����\n4. ����\n5.�� �� ����\n");
		printf("���� �� �� �� = %d\n", taskCount);
		printf("------------------\n");
		scanf_s("%d", &choice);

		int terminate = 0; // ���Ḧ ���� ����
		int delIndex = -1; // case2(����)���� ����� ����
		int changeIndex = -1; // case5(����)���� ����� ����
		char ch; // �� �� ������ ���۸� �ޱ� ���� ����


		switch (choice) {
		case 1: // �� �� �Է� ���
			addTask(tasks[taskCount]); // �� �� �Է� �Լ��� �̵�
			taskCount++; // ���� ���ڿ��� �Ѿ�� ���� +1, 1�� ���Է½� ���� ���ڿ��� �Էµ�
			break;
		case 2: // �� �� ���� ���
			printf("������ �� ���� ��ȣ�� �Է����ּ���. (1���� ����):");
			scanf_s("%d", &delIndex); // �Է��� ��ȣ�� ������ ����
			if (delIndex > taskCount || delIndex <= 0) {
				printf("���� ������ ������ϴ�.\n"); // ��ȣ�� ������ ���� ���� �� �˸�
			}
			else {
				delTask(delIndex, taskCount); // �� �� ���� �Լ��� �̵�
				taskCount -= 1; // �����Ǿ� �� ��ȣ�� �ſ�� ���� ���� ��ȣ�� ���� 1�� ����
			}
			break;
		case 3: // �� �� ��� ��� ���
			printf("�� �� ���\n");
			printTask(taskCount); // �� �� ��� ��� �Լ��� �̵�
			printf("\n");
			break;
		case 4: // ���� ���
			terminate = 1;
			break;
		case 5: // ���� ���� ���
			printf("������ ���� ��ȣ�� �Է����ּ���. (1���� ����):");
			scanf_s("%d", &changeIndex); // �Է��� ��ȣ�� ������ ����
			if (changeIndex > taskCount || changeIndex <= 0) {
				printf("���� ������ ������ϴ�.\n"); // ��ȣ�� ������ ���� ���� �� �˸�
			}
			else {
				printf("�� ���� �Է��ϼ��� (���� ���� �Է��ϼ���):");
				scanf_s("%s", tasks[changeIndex - 1], (int)sizeof(tasks[changeIndex - 1]));
				// 2���� �迭���� 0���� ���� �ǹǷ� �Է¹��� ��ȣ�� -1�� �ش��ϴ� ���ڿ��� ������ �Է¹��� �� �Ϸ� ����
				printf("%d. %s : �� ���� �����մϴ�.\n", changeIndex, tasks[changeIndex - 1]);
			}
			break;
		default:
			printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n"); // 1����5�� �ƴ� ���ڸ� �Է��� �� ���
		}

		if (terminate == 1) {
			printf("���Ḧ �����ϼ̽��ϴ�. ���α׷��� �����մϴ�.\n");
			break;
		}


		if (taskCount == 10) {
			printf("�� ���� �� á���ϴ�. ���α׷��� �����մϴ�.");
			terminate = 1; // �� ���� 10���� �ɽ� ����
			break;
		}
	}
}
// �� �� �Է� �Լ� ����
void addTask(char task[]) {
	printf("�� ���� �Է��ϼ��� (���� ���� �Է��ϼ���): ");
	scanf_s("%s", tasks[taskCount], (int)sizeof(tasks[taskCount])); // �Է��� �� ���� tasks 2���� �迭�� ���ڿ��� �Է�
	printf("�� �� ""%s""�� ����Ǿ����ϴ�\n\n", tasks[taskCount]);
}
// �� �� ���� �Լ� ����
void delTask(int delIndex, int taskCount) {
	printf("%d. %s : �� ���� �����մϴ�.\n", delIndex, tasks[delIndex - 1]);


	strcpy_s(tasks[delIndex - 1], sizeof(tasks[delIndex - 1]), "");
	// 2���� �迭���� 0���� ���� �ǹǷ� �Է¹��� ��ȣ�� -1�� �ش��ϴ� ���ڿ��� ������ �� ����

	for (int i = delIndex; i < taskCount + 1; i++) {
		strcpy_s(tasks[i - 1], sizeof(tasks[i]), tasks[i]);
	}
}
// �� �� ��� ��� �Լ� ����
void printTask(int taskCount) {
	for (int i = 0; i < taskCount; i++) {
		printf("%d. %s \n", i + 1, tasks[i]); // �� ���� ����� �� ���
	}
}