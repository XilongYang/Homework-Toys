/*
	�γ���Ϣ����ģ��
	���ߣ�������
	�汾��1.2
*/
#include "studentManagerData.h"

void resultInfoManager(studInfo *tmpStudent, courInfo *tmpCourse, resuInfo* tmpResult)
{
	// ��������
	void resultInfoMenu();
	void resultInfoInput(studInfo*, courInfo*, resuInfo*);
	void resultInfoLook(resuInfo *, int);
	void resultInfoDelete(resuInfo*, int);
	int resultInfoMenuChoice = 1;
	// ��Ҫ���ܲ���
	while (resultInfoMenuChoice)
	{
		resultInfoMenu();
		printf("Enter your choice<0-6>:");
		scanf("%d", &resultInfoMenuChoice);
		fflush(stdin);
		switch (resultInfoMenuChoice)
		{
		case 1:
			resultInfoInput(tmpStudent, tmpCourse, tmpResult);
			break;
		case 2:
			resultInfoDelete(tmpResult, 1);
			break;
		case 3:
			resultInfoDelete(tmpResult, 0);
			break;
		case 4:
			resultInfoLook(tmpResult, 1);
			break;
		case 5:
			resultInfoLook(tmpResult, 0);
			break;
		case 6:
			resultInfoLook(tmpResult, 2);
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

void resultInfoMenu()
{
	// ���Դ�ӡѡ��ģ������˵��ĺ���
	system("CLS");
	printf("\n%40s\n", "ѡ����Ϣ����ϵͳ");
	printf("%50s\n", "------------------------------------");
	printf("%39s\n", "1.ѡ          ��");
	printf("\n%39s\n", "2.��ѧ��ɾ����Ϣ");
	printf("\n%39s\n", "3.���κ�ɾ����Ϣ");
	printf("\n%39s\n", "4.��ѧ�Ų鿴��Ϣ");
	printf("\n%39s\n", "5.���κŲ鿴��Ϣ");
	printf("\n%39s\n", "6.�鿴��  ����Ϣ");
	printf("\n%39s\n", "0.��  ��  ��  ��");
	printf("%50s\n", "------------------------------------");
}

void resultInfoInputMenu(resuInfo *tmpResu, int SID, int Term)
{
	// ���Դ�ӡѡ�ι��̵Ľ���ĺ���
	int i;
	system("CLS");
	printf("%-4s %-10s %-4s %-15s %4s %5s\n", "S.ID", "Name", "C.ID", "Course", "Term", "Score");
	printf("------------------------------------\n");
	for (i = 0; i < S; i++)
	{
		if (tmpResu[i].sNo == SID && tmpResu[i].sTerm == Term && tmpResu[i].cNo != 0)
		{
			printf("%-4d %-10s %-4d %-15s %4d %5d\n", tmpResu[i].sNo, tmpResu[i].sName,
				tmpResu[i].cNo, tmpResu[i].cName, tmpResu[i].sTerm, tmpResu[i].score);
		}
	}
}

void resultStudnumInfoSort(resuInfo *tmpResu)
{
	// ���Զ�ѡ����Ϣ��������ĺ���
	int i, j;
	resuInfo tmpData;
	// ð������ѧ��Ϊ����ѧ����ͬʱ���κ�����
	for (i = 0; i < S - 1; i++)
	{
		for (j = 0; j < S - i - 1; j++)
		{
			if (tmpResu[j].sNo > tmpResu[j + 1].sNo && tmpResu[j + 1].sNo != 0)
			{
				tmpData = tmpResu[j];
				tmpResu[j] = tmpResu[j + 1];
				tmpResu[j + 1] = tmpData;
			}
			else if (tmpResu[j].sNo == tmpResu[j + 1].sNo && tmpResu[j].cNo > tmpResu[j + 1].cNo 
				&& tmpResu[j + 1].sNo != 0)
			{
				tmpData = tmpResu[j];
				tmpResu[j] = tmpResu[j + 1];
				tmpResu[j + 1] = tmpData;
			}
		}
	}
}

void resultInfoInput(studInfo *inStudent, courInfo *tmpCourse, resuInfo *inResult)
{
	// ѡ����Ϣ���뺯��
	int i, j;
	courInfo *tmpCurrentCourse;
	// �ҵ���Ϣβ��
	for (i = 0; i < S && inResult[i].sNo != 0; i++);
	// ��������
	system("CLS");
	printf("Enter student ID(0 to exit): ");
	scanf("%d", &inResult[i].sNo);
	getchar();
	for (j = 0; j < N && inStudent[j].sNo != inResult[i].sNo; j++);
	if (inStudent[j].sNo != inResult[i].sNo || inResult[i].sNo == 0)
	{
		if (inResult[i].sNo)
		{
			printf("No student found!");
			inResult[i].sNo = 0;
		}
	}
	else
	{
		strcpy(inResult[i].sName, inStudent[j].sName);
		printf("Enter term info: ");
		scanf("%d", &inResult[i].sTerm);
		resultInfoInputMenu(inResult, inResult[i].sNo, inResult[i].sTerm);
		printf("Enter course ID (0 to exit): ");
		scanf("%d", &inResult[i].cNo);
	}
	while (inResult[i].cNo != 0)
	{
		for (tmpCurrentCourse = tmpCourse; tmpCurrentCourse != NULL && tmpCurrentCourse->cNo != inResult[i].cNo;
			tmpCurrentCourse = tmpCurrentCourse->next);
		if (inResult[i].cNo == 0)
		{
			inResult[i].sNo = 0;
			break;
		}
		else if (tmpCurrentCourse == NULL)
		{
			printf("No course found!\n");
			inResult[i].sNo = 0;
			break;
		}
		strcpy(inResult[i].cName, tmpCurrentCourse->cName);
		i++;
		strcpy(inResult[i].sName, inResult[i - 1].sName);
		inResult[i].sNo = inResult[i - 1].sNo;
		inResult[i].sTerm = inResult[i - 1].sTerm;
		resultInfoInputMenu(inResult, inResult[i].sNo, inResult[i].sTerm);
		printf("Enter course ID (0 to exit): ");
		scanf("%d", &inResult[i].cNo);
		getchar();
	}
	inResult[i].sNo = 0;
	printf("\nPress <Enter> to continue.\n");
	getchar();
}

void resultInfoLook(resuInfo *tmpResult, int mode)
{
	// ���Բ鿴�γ���Ϣ�ĺ���
	system("ClS");
	int i, j, flg = 1, inID;
	// ����
	resultStudnumInfoSort(tmpResult);
	// �ֲ鿴��ʽ
	if (mode == 1)
	{
		// ��ѧ�Ž��в鿴
		printf("Enter student ID: ");
		scanf("%d", &inID);
		printf("%-4s %-10s %-4s %-15s %4s %5s\n", "S.ID", "Name", "C.ID", "Course", "Term", "Score");
		printf("------------------------------------\n");
		for (i = 0; i < S && tmpResult[i].sNo != 0; i++)
		{
			if (tmpResult[i].sNo == inID)
			{
				printf("%-4d %-10s %-4d %-15s %4d %5d\n", tmpResult[i].sNo, tmpResult[i].sName,
					tmpResult[i].cNo, tmpResult[i].cName, tmpResult[i].sTerm, tmpResult[i].score);
				flg = 0;
			}
		}
		if (flg) printf("No data!\n");
	}
	else if (mode == 2)
	{
		// �鿴������Ϣ
		printf("%-4s %-10s %-4s %-15s %4s %5s\n", "S.ID", "Name", "C.ID", "Course", "Term", "Score");
		printf("------------------------------------\n");
		for (i = 0; i < S && tmpResult[i].sNo != 0; i++)
		{
			printf("%-4d %-10s %-4d %-15s %4d %5d\n", tmpResult[i].sNo, tmpResult[i].sName,
					tmpResult[i].cNo, tmpResult[i].cName, tmpResult[i].sTerm, tmpResult[i].score);
			flg = 0;
		}
		if (flg) printf("No data!\n");
	}
	else
	{
		// ���κŽ��в鿴
		printf("Enter course ID: ");
		scanf("%d", &inID);
		printf("%-4s %-10s %-4s %-15s %4s %5s\n", "S.ID", "Name", "C.ID", "Course", "Term", "Score");
		printf("------------------------------------\n");
		for (i = 0; i < S && tmpResult[i].sNo != 0; i++)
		{
			if (tmpResult[i].cNo == inID)
			{
				printf("%-4d %-10s %-4d %-15s %4d %5d\n", tmpResult[i].sNo, tmpResult[i].sName,
					tmpResult[i].cNo, tmpResult[i].cName, tmpResult[i].sTerm, tmpResult[i].score);
				flg = 0;
			}
		}
		if (flg) printf("No data!\n");
	}
	printf("\nPress <Enter> to continue.");
	getchar();
	getchar();
}

void resultInfoDelete(resuInfo *tmpResu, int mode)
{
	// ����ɾ��ѡ����Ϣ�ĺ���
	system("CLS");
	int i = 0, j, delSID, delCID, delTerm, flg = 1;
	char delChoice;
	// ������ɾ����ʽ
	if (mode)
	{
		// ��ѧ��ɾ��
		printf("Enter a student ID: ");
		scanf("%d", &delSID);
		printf("%-4s %-10s %-4s %-15s %4s %5s\n", "S.ID", "Name", "C.ID", "Course", "Term", "Score");
		printf("------------------------------------\n");
		for (i = 0; i < S; i++)
		{
			if (tmpResu[i].sNo == delSID)
			{
				printf("%-4d %-10s %-4d %-15s %4d %5d\n", tmpResu[i].sNo, tmpResu[i].sName,
					tmpResu[i].cNo, tmpResu[i].cName, tmpResu[i].sTerm, tmpResu[i].score);
			}
		}
		printf("Enter a course ID: ");
		scanf("%d", &delCID);
		getchar();
		printf("Delete the data of the course <y/n>?");
		scanf("%c", &delChoice);
		if (delChoice == 'Y' || delChoice == 'y')
		{
			for (i = 0; i < S; i++)
			{
				if (tmpResu[i].sNo == delSID && tmpResu[i].cNo == delCID)
				{
					j = i;
					while (++j < N)
					{
						tmpResu[j - 1] = tmpResu[j];
					}
					tmpResu[j - 1].sNo = 0;
					tmpResu[j - 1].sName[0] = '\0';
					tmpResu[j - 1].cNo = '0';
					tmpResu[j - 1].cName[0] = '\0';
					flg = 0;
				}
			}
			if (flg)
			{
				printf("No info found!");
			}
			else
			{
				printf("Complete!");
			}
		}
	}
	else
	{
		// ���κ�ɾ��
		printf("Enter a course ID: ");
		scanf("%d", &delCID);
		printf("Enter a term info:");
		scanf("%d", &delTerm);
		getchar();
		printf("%-4s %-10s %-4s %-15s %4s %5s\n", "S.ID", "Name", "C.ID", "Course", "Term", "Score");
		printf("------------------------------------\n");
		for (i = 0; i < S; i++)
		{
			if (tmpResu[i].sTerm == delTerm && tmpResu[i].cNo == delCID)
			{
				printf("%-4d %-10s %-4d %-15s %4d %5d\n", tmpResu[i].sNo, tmpResu[i].sName,
					tmpResu[i].cNo, tmpResu[i].cName, tmpResu[i].sTerm, tmpResu[i].score);
			}
		}
		printf("Delete the data of the course <y/n>?");
		scanf("%c", &delChoice);
		if (delChoice == 'Y' || delChoice == 'y')
		{
			for (i = 0; i < S; i++)
			{
				if (tmpResu[i].sTerm == delTerm && tmpResu[i].cNo == delCID)
				{
					j = i;
					while (++j < N)
					{
						tmpResu[j - 1] = tmpResu[j];
					}
					tmpResu[j - 1].sNo = 0;
					tmpResu[j - 1].sName[0] = '\0';
					tmpResu[j - 1].cNo = '0';
					tmpResu[j - 1].cName[0] = '\0';
					flg = 0;
				}
			}
			if (flg)
			{
				printf("No info found!");
			}
			else
			{
				printf("Complete!");
			}
		}
	}
	printf("\nPress <Enter> to continue.");
	getchar();
	getchar();
}