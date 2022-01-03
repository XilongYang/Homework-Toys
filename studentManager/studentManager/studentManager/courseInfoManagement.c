/*
	�γ���Ϣ����ģ��
	���ߣ�������
	�汾��1.0
*/

#include "studentManagerData.h"

void courseInfoManager(courInfo **headCourseInfo)
{
	// ��������
	void courseInfoMenu();
	void courseInfoInput(courInfo*);
	void courseInfoEdit(courInfo**);
	void courseInfoDelete(courInfo**);
	void courseInfoLook(courInfo*);
	void courseInfoSort(courInfo**);
	int courseInfoMenuChoice = 1;
	// ��Ҫ���ܲ���
	while (courseInfoMenuChoice)
	{
		courseInfoMenu();
		printf("Enter your choice<0-5>:");
		scanf("%d", &courseInfoMenuChoice);
		switch (courseInfoMenuChoice)
		{
		case 1:
			courseInfoInput(*headCourseInfo);
			break;
		case 2:
			courseInfoEdit(headCourseInfo);
			break;
		case 3:
			courseInfoDelete(headCourseInfo);
			break;
		case 4:
			courseInfoLook(*headCourseInfo);
			break;
		case 5:
			courseInfoSort(headCourseInfo);
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
}

void courseInfoMenu()
{
	// ���Դ�ӡ�γ���Ϣ����ģ��˵��ĺ���
	system("CLS");
	printf("\n%40s\n", "�γ���Ϣ����ϵͳ");
	printf("%50s\n", "------------------------------------");
	printf("%39s\n", "1.��        ��");
	printf("\n%39s\n", "2.��        ��");
	printf("\n%39s\n", "3.ɾ        ��");
	printf("\n%39s\n", "4.��        ��");
	printf("\n%39s\n", "5.���ݿκ�����");
	printf("\n%39s\n", "0.�� ��  �� ��");
	printf("%50s\n", "------------------------------------");
}

void courseInfoInput(courInfo *headCourse)
{
	// �����½��γ���Ϣ�ĺ���
	int courseID;
	courInfo *endCourse;
	// �ҵ���Ϣβ��
	for (endCourse = headCourse; endCourse->next != NULL; endCourse = endCourse->next);
	system("CLS");
	// ������Ϣ
	printf("Enter a course ID: ");
	scanf("%d",&courseID);
	getchar();
	while (courseID)
	{
		if (0 != endCourse->cNo)
		{
			endCourse->next = (courInfo*)malloc(sizeof(courInfo));
			endCourse = endCourse->next;
			endCourse->next = NULL;
		}
		endCourse->cNo = courseID;
		printf("Enter course name:");
		fgets(endCourse->cName, 80, stdin);
		char *p = endCourse->cName;
		for (; *p != '\0'; p++)
		{
			if (*p == '\n') *p = '\0';
		}
		printf("Enter course credit:");
		scanf("%d", &endCourse->cCredit);
		printf("Enter course period:");
		scanf("%d", &endCourse->cTime);
		system("CLS");
		printf("Enter course ID:");
		scanf("%d", &courseID);
		getchar();
	}
}

void courseInfoEdit(courInfo **headCourse)
{
	// ���Ա༭�γ���Ϣ�ĺ���
	int courseID;
	char saveChangeChoice;
	courInfo *currentCourse, *tmpCourse;
	system("CLS");
	// ����γ̺Ų��ж��γ��Ƿ����
	printf("Enter a course ID:");
	scanf("%d", &courseID);
	getchar();
	for (currentCourse = *headCourse;currentCourse != NULL && currentCourse->cNo != courseID;
		currentCourse = currentCourse->next);
	if (currentCourse != NULL)
	{
		// ������������ʱ������
		tmpCourse = (courInfo*)malloc(sizeof(courInfo));
		tmpCourse->cNo = courseID;
		printf("Enter course name:");
		fgets(tmpCourse->cName, 80, stdin);
		char *p = tmpCourse->cName;
		for (; *p != '\0'; p++)
		{
			if (*p == '\n') *p = '\0';
		}
		printf("Enter course credit:");
		scanf("%d", &tmpCourse->cCredit);
		printf("Enter course period:");
		scanf("%d", &tmpCourse->cTime);
		getchar();
		// ȷ�����룬�����ݴ���ʱ����ȡ��
		printf("Save changes <y/n>?");
		scanf("%c", &saveChangeChoice);
		if (saveChangeChoice == 'Y' || saveChangeChoice == 'y')
		{
			tmpCourse->next = currentCourse->next;
			if (currentCourse->cNo == (*headCourse)->cNo)
			{
				*headCourse = tmpCourse;
			}
			else
			{
				for (currentCourse = *headCourse; currentCourse->next != NULL && (currentCourse->next)->cNo != courseID;
					currentCourse = currentCourse->next);
				currentCourse->next = tmpCourse;
			}
			printf("Edit complete!\n");
			getchar();
		}
	}
	else
	{
		printf("No course found!\n");
	}
	printf("\nPress <Enter> to continue.");
	getchar();
}

void courseInfoDelete(courInfo **headCourse)
{
	// ����ɾ���γ���Ϣ�ĺ���
	int courseID;
	char deleteChangeChoice;
	courInfo *currentCourse;
	system("CLS");
	// ����κţ��ж��γ��Ƿ����
	printf("Enter a course ID:");
	scanf("%d", &courseID);
	getchar();
	for (currentCourse = *headCourse; currentCourse != NULL && currentCourse->cNo != courseID;
		currentCourse = currentCourse->next);
	if (currentCourse != NULL)
	{
		// ȷ��ɾ��
		printf("Delete course <y/n>?");
		scanf("%c", &deleteChangeChoice);
		if (deleteChangeChoice == 'Y' || deleteChangeChoice == 'y')
		{
			// ���������ɾ��������δʹ��ͷ�ڵ���һ���Եúܸ���
			if (currentCourse->next == NULL)
			{
				if (currentCourse->cNo == (*headCourse)->cNo)
				{
					(*headCourse)->next = NULL;
					(*headCourse)->cNo = 0;
				}
				else
				{
					for (currentCourse = *headCourse; currentCourse->next != NULL && (currentCourse->next)->cNo != courseID;
						currentCourse = currentCourse->next);
					currentCourse->next = NULL;
				}
			}
			else
			{
				if (currentCourse->cNo == (*headCourse)->cNo)
				{
					*headCourse = currentCourse->next;
				}
				else
				{
					for (currentCourse = *headCourse; currentCourse->next != NULL && (currentCourse->next)->cNo != courseID;
						currentCourse = currentCourse->next);
					currentCourse->next = (currentCourse->next)->next;
				}
			}
			printf("Delete complete!\n");
			getchar();
		}
	}
	else
	{
		printf("No course found!\n");
	}
	printf("\nPress <Enter> to continue.");
	getchar();
}

void courseInfoLook(courInfo *headCourse)
{
	// ���Բ鿴�γ���Ϣ�ĺ���
	int flg = 1;
	courInfo *currentCourse;
	// ��������ӡ��ͷ
	system("CLS");
	printf("%-4s %-20s %6s %6s\n", "ID", "Name", "Credit", "Period");
	printf("---------------------------------------\n");
	// ��ӡ�γ���Ϣ
	for (currentCourse = headCourse; currentCourse != NULL && currentCourse->cNo != 0; currentCourse = currentCourse->next)
	{
		flg = 0;
		printf("%4d %-20s %6d %6d\n", currentCourse->cNo, currentCourse->cName, currentCourse->cCredit, currentCourse->cTime);
	}
	if (flg) printf("No data!\n");
	printf("\nPress <Enter> to continue.\n");
	getchar();
	getchar();
}

void courseInfoSwap(courInfo *alphaCourse, courInfo *betaCourse)
{
	// �����ڲ��ƻ����������½������ڵ������
	courInfo tmpCourse;
	courInfo *tmpNextAlpha, *tmpNextBeta;
	// ����ڵ�ָ����Ϣ
	tmpNextAlpha = alphaCourse->next;
	tmpNextBeta = betaCourse->next;
	// ���ݽ���
	tmpCourse = *alphaCourse;
	*alphaCourse = *betaCourse;
	*betaCourse = tmpCourse;
	// ָ��ָ�
	alphaCourse->next = tmpNextAlpha;
	betaCourse->next = tmpNextBeta;
}

void courseInfoSort(courInfo **headCourse)
{
	// ���ԶԿγ���Ϣ��������ĺ���
	int courseSum, i, j;
	courInfo *tmpCourse;
	// ����γ���Ϣ����
	for (tmpCourse = *headCourse, courseSum = 0; tmpCourse != NULL; tmpCourse = tmpCourse->next, courseSum++);
	// ð������
	for (i = 0; i < courseSum - 1; i++)
	{
		for (j = 0, tmpCourse = *headCourse; j < courseSum - i - 1 && tmpCourse->next != NULL;
			j++, tmpCourse = tmpCourse->next)
		{
			if (tmpCourse->cNo > (tmpCourse->next)->cNo)
			{
				courseInfoSwap(tmpCourse, tmpCourse->next);
			}
		}
	}
	printf("Sort complete.");
	getchar();
	getchar();
}