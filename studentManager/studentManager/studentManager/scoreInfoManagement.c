/*
	�ɼ�����ģ��
	���ߣ�������
	�汾��v1.0
*/

#include "studentManagerData.h"

void scoreInfoManager(resuInfo *tmpResult)
{
	// ��������
	void scoreInfoMenu();
	void scoreInfoInput(resuInfo *);
	void scoreInfoEdit(resuInfo *);
	int resultInfoMenuChoice = 1;
	// ��Ҫ���ܲ���
	while (resultInfoMenuChoice)
	{
		scoreInfoMenu();
		printf("Enter your choice<0-2>:");
		scanf("%d", &resultInfoMenuChoice);
		fflush(stdin);
		switch (resultInfoMenuChoice)
		{
		case 1:
			scoreInfoInput(tmpResult);
			break;
		case 2:
			scoreInfoEdit(tmpResult);
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

void scoreInfoMenu()
{
	// ��ӡ�ɼ�����ģ�����˵�
	system("CLS");
	printf("\n%40s\n", "�ɼ���Ϣ����ϵͳ");
	printf("%50s\n", "------------------------------------");
	printf("%39s\n", "1.��  ��  ¼  ��");
	printf("\n%39s\n", "2.��  ��  ��  ��");
	printf("\n%39s\n", "0.��  ��  ��  ��");
	printf("%50s\n", "------------------------------------");
}

void scoreInfoInputMenu()
{
	// ��ӡ�ɼ����벿�ֲ˵�
	int i;
	system("CLS");
	printf("%-4s %-10s %-4s %-15s %4s %5s\n", "S.ID", "Name", "C.ID", "Course", "Term", "Score");
	printf("------------------------------------\n");
}

void scoreInfoInput(resuInfo *inResult)
{
	// ��������ɼ��ĺ���
	int i, flg =1, scoreCID, scoreTerm, tmpScore[S];
	char scoreSaveChoice;
	courInfo *tmpCurrentCourse;
	// ����γ���Ϣ
	system("CLS");
	printf("Enter course ID: ");
	scanf("%d", &scoreCID);
	getchar();
	printf("Enter term info: ");
	scanf("%d", &scoreTerm);
	resultInfoInputMenu();
	// �Բ��ҵ���ѡ����Ϣ���гɼ�����
	for (i = 0; i < S; i++)
	{
		tmpScore[i] = 0;
		if (inResult[i].cNo == scoreCID && inResult[i].sTerm == scoreTerm &&inResult[i].cNo != 0)
		{
			printf("%-4d %-10s %-4d %-15s %4d    ", inResult[i].sNo, inResult[i].sName,
				inResult[i].cNo, inResult[i].cName, inResult[i].sTerm);
			scanf("%d", &tmpScore[i]);
			flg = 0;
		}
	}
	fflush(stdin);
	if (flg)
	{
		printf("No result data found!\n");
	}
	else
	{
		// ȷ�ϸĶ�
		printf("Save changes? <y/n>\n");
		getchar();
		scanf("%c", &scoreSaveChoice);
		if (scoreSaveChoice == 'Y' || scoreSaveChoice == 'y')
		{
			for (i = 0; i < S; i++)
			{
				if (inResult[i].cNo == scoreCID && inResult[i].sTerm == scoreTerm && inResult[i].cNo != 0)
				{
					inResult[i].score = tmpScore[i];
				}
			}
			printf("Complete!\n");
		}
	}
	printf("\nPress <Enter> to continue.\n");
	getchar();
	getchar();
}

void scoreInfoEdit(resuInfo *inResult)
{
	// ���Ա༭�ɼ���Ϣ�ĺ���
	int i, flg = 1, scoreSID, scoreCID, scoreTerm, tmpScore[S];
	char scoreSaveChoice;
	courInfo *tmpCurrentCourse;
	system("CLS");
	// ����ѧ�ſκŵ���Ϣ
	printf("Enter student ID: ");
	scanf("%d", &scoreSID);
	printf("Enter course ID: ");
	scanf("%d", &scoreCID);
	printf("Enter term info: ");
	scanf("%d", &scoreTerm);
	resultInfoInputMenu();
	// �ı�������Ϣ
	for (i = 0; i < S; i++)
	{
		tmpScore[i] = 0;
		if (inResult[i].sNo == scoreSID && inResult[i].cNo == scoreCID 
			&& inResult[i].sTerm == scoreTerm && inResult[i].cNo != 0)
		{
			printf("%-4d %-10s %-4d %-15s %4d %5d\n", inResult[i].sNo, inResult[i].sName,
				inResult[i].cNo, inResult[i].cName, inResult[i].sTerm, inResult[i].score);
			printf("Enter new score: ");
			scanf("%d", &tmpScore[i]);
			flg = 0;
		}
	}
	fflush(stdin);
	if (flg)
	{
		printf("No result data found!\n");
	}
	else
	{
		// ȷ�ϸĶ�
		printf("Save changes? <y/n>\n");
		getchar();
		scanf("%c", &scoreSaveChoice);
		if (scoreSaveChoice == 'Y' || scoreSaveChoice == 'y')
		{
			for (i = 0; i < S; i++)
			{
				if (inResult[i].sNo == scoreSID && inResult[i].cNo == scoreCID
					&& inResult[i].sTerm == scoreTerm && inResult[i].cNo != 0)
				{
					inResult[i].score = tmpScore[i];
				}
			}
			printf("Complete!\n");
		}
	}
	printf("\nPress <Enter> to continue.\n");
	getchar();
	getchar();
}