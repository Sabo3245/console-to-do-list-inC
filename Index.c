#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char description[100];
	int isDone;
} Task;


void addTask(Task* tasks , int* taskCount) {

	printf("Enter Task Description \n");
	fgets(tasks[*taskCount].description , 100 , stdin);

	printf("Created task : %s \n", tasks[*taskCount].description);
	
	(*taskCount)++;
	
}

void markDone(Task* tasks, int* taskCount) {
	int choice;
	printf("\n");
	printf("\n");
	printf("Which Task to Mark as Done \n");
	
	printf("Enter your choice : ");
	scanf_s("%d", &choice);
	
	if (choice <= *taskCount) {
		tasks[choice - 1].isDone = 1;
		printf("Task %d. was marked as done \n", choice);
		
	}
	else {
		printf("invalid Task \n");
		
	}
}

void deleteTask(Task* tasks, int* taskCount) {
	int choice;
	printf("\n");
	printf("\n");
	printf("Which Task to Delete \n");

	printf("Enter your choice : ");
	scanf("%d", &choice);
	
	if (choice <= *taskCount && choice >= 1) {
		printf("Task deleted.\n");

		for (int i = choice - 1; i < (*taskCount) - 1; i++) {

			tasks[i] = tasks[i + 1];
		}
		(*taskCount)--;
		
	}
	else {
		printf("invalid Task");
	}
}


void viewTasks(Task* tasks , int* taskCount) {
	int choice;
	printf("ALL TASKS : \n");
	for (int i = 0; i < *taskCount; i++)
	{
		printf("%d. %s", i+1, tasks[i].description);
	}

	do {
		printf("\n");
		printf("\n");
		printf("Menu \n");
		printf("1. Mark task as done \n");
		printf("2. Delete Task \n");
		printf("3. Return to Main Screen \n");

		printf("Enter your choice : ");
		scanf("%d", &choice);
		
		switch (choice) {
		case 1:
			system("cls");
			for (int i = 0; i < *taskCount; i++)
			{
				printf("%d. %s", i + 1, tasks[i].description);
			}

			printf("Completed \n");
			markDone(tasks, taskCount);
			printf("press enter to continue");
			getchar();
			getchar();

			system("cls");
			for (int i = 0; i < *taskCount; i++)
			{
				printf("%d. %s", i + 1, tasks[i].description);
			}

			break;
		case 2: 
			system("cls");
			for (int i = 0; i < *taskCount; i++)
			{
				printf("%d. %s", i + 1, tasks[i].description);
			}

			printf("Completed \n");
			deleteTask(tasks, taskCount);
			printf("press enter to continue");
			getchar();
			getchar();

			system("cls");
			for (int i = 0; i < *taskCount; i++)
			{
				printf("%d. %s", i + 1, tasks[i].description);
			}

			

			break;
			break;
		case 3: break;
		}

	} while (choice != 3);
}


int main() {
	
	Task tasks[100];

	int taskCount = 0;

	int choice;

	//Interface 
	do {
		printf("\n");
		printf("\n");
		printf("1. Create new Task \n");
		printf("2. View Exisiting tasks \n");
		printf("3. Save and exit \n");

		printf("Enter your choice : ");
		scanf_s("%d", &choice);
		getchar();

		switch (choice) {
		case 1:
			system("cls");
			addTask(tasks, &taskCount);
			printf("Current number of tasks : %d \n", taskCount);
			printf("Press Enter To Go Back To Main Screen");
			getchar();
			system("cls");
			break;

		case 2:
			system("cls");
			viewTasks(tasks, &taskCount);
			printf("Press Enter To Go Back To Main Screen");
			getchar();
			system("cls");
			break;

		case 3:
			printf("Saved");
			break;
		default: printf("invalid choice");
		}
	} while (choice != 3);

	


	
	return 0;
}