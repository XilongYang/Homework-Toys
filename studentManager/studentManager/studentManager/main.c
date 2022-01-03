/*
	������
	���ߣ�������
	�汾��1.0
*/

#include "studentManagerData.h"
#include "studentManagerTools.h"

int main()
{
	//��������
	int mainMenuChoice = 1;
	studInfo students[N];
	courInfo *headCourseInfo = (courInfo*)malloc(sizeof(courInfo));
	resuInfo results[S];
	//��Ҫ���ܲ���
	initInfo(students, headCourseInfo, results);
	loadData(students, headCourseInfo, results);
	while (mainMenuChoice)
	{
		mainMenu();
		printf("Enter your choice<0-5> :");
		scanf("%d", &mainMenuChoice);
		switch (mainMenuChoice)
		{
		case 1:
			studentInfoManager(students);
			break;
		case 2:
			courseInfoManager(&headCourseInfo);
			break;
		case 3:
			resultInfoManager(students, headCourseInfo, results);
			break;
		case 4:
			scoreInfoManager(results);
			break;
		case 5:
			infoSearchManager(students, headCourseInfo, results);
			break;
		case 0:
			break;
		default:
			printf("Worng choice!");
			getchar();
			getchar();
			break;
		}
	}
	saveData(students, headCourseInfo, results);
	return 0;
}