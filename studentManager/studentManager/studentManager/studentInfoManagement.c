/*
	ѧ����Ϣ����ģ�飬��������غ�������������������������studentInfoManager������ʹ�����ģ�顣
	���ߣ�������
	�汾��1.0
*/

#include "studentManagerData.h"

void studentInfoManager(studInfo *tmpStudent)
{
	// ��������
	void studentInfoMenu();
	void studentInfoInput(studInfo*);
	void studentInfoLook(studInfo*);
	void studentInfoDelete(studInfo*);
	void studentInfoEdit(studInfo*);
	void studentInfoSort(studInfo*);
	int studentInfoMenuChoice = 1;
	// ��Ҫ����
	while (studentInfoMenuChoice)
	{
		studentInfoMenu();
		printf("Enter your choice<0-5>:");
		scanf("%d", &studentInfoMenuChoice);
		fflush(stdin);
		switch (studentInfoMenuChoice)
		{
		case 1:
			studentInfoInput(tmpStudent);
			break;
		case 2:
			studentInfoEdit(tmpStudent);
			break;
		case 3:
			studentInfoDelete(tmpStudent);
			break;
		case 4:
			studentInfoLook(tmpStudent);
			break;
		case 5:
			studentInfoSort(tmpStudent);
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

void studentInfoMenu()
{
	//���Դ�ӡѧ������ģ��Ĳ˵�
	system("CLS");
	printf("\n%40s\n", "ѧ����Ϣ����ϵͳ");
	printf("%50s\n", "------------------------------------");
	printf("%39s\n", "1.��        ��");
	printf("\n%39s\n", "2.��        ��");
	printf("\n%39s\n", "3.ɾ        ��");
	printf("\n%39s\n", "4.��        ��");
	printf("\n%39s\n", "5.����ѧ������");
	printf("\n%39s\n", "0.�� ��  �� ��");
	printf("%50s\n", "------------------------------------");
}

void studentInfoInput(studInfo *inStudent, int n)
{
	// �����½�ѧ����Ϣ����
	// ��ѭ���ҵ�ѧ�����͵�β��������
	int i;
	for (i = 0; i < N && inStudent[i].sNo != 0; i++);
	system("CLS");
	// �������ݣ� ѧ��Ϊ��ʱ����
	printf("Enter student ID(0 to exit): ");
	scanf("%d", &inStudent[i].sNo);
	while (inStudent[i].sNo != 0)
	{
		printf("Enter name: ");
		scanf("%s", inStudent[i].sName);
		printf("Enter sex: ");
		getchar();
		scanf("%c", &inStudent[i].sSex);
		printf("Enter address: ");
		scanf("%s", inStudent[i].sAddress);
		i++;
		system("CLS");
		printf("Enter student ID(0 to exit): ");
		scanf("%d", &inStudent[i].sNo);
	}
}

void studentInfoLook(studInfo *tmpStudent)
{
	// ���Բ鿴ȫ��ѧ����Ϣ�ĺ���
	// ��������ӡ��ͷ�����忪��flg�����ж��Ƿ���ѧ����Ϣ����ʼ��
	system("ClS");
	int i, flg = 1;
	printf("%-4s %-10s %3s %-15s\n", "ID", "Name", "Sex", "Address");
	printf("------------------------------------\n");
	//����ѧ����Ϣ���飬������Ϣ��رտ���flg
	for (i = 0; i < N && tmpStudent[i].sNo != 0; i++)
	{
		printf("%4d %-10s %3c %-15s\n", tmpStudent[i].sNo, tmpStudent[i].sName,
			tmpStudent[i].sSex, tmpStudent[i].sAddress);
		flg = 0;
	}
	//��flg�Ǵ�״̬����ʾû����Ϣ
	if (flg)
	{
		printf("No data!\n");
	}
	printf("\nPress <Enter> to continue.");
	getchar();
	getchar();
}

void studentInfoDelete(studInfo *tmpStud)
{
	// ����ɾ��ѧ�����ݵĺ���
	// ����������Ҫɾ����ѧ����Ϣ��ѧ��
	system("CLS");
	int i = 0, delID;
	char delChoice;
	printf("Enter a student ID: ");
	scanf("%d", &delID);
	getchar();
	// ����ѧ����ϢѰ�Ҹ�ѧ��
	for (i = 0; i < N && tmpStud[i].sNo != delID; i++);
	// �ж��Ƿ��ҵ���ѧ��
	if (tmpStud[i].sNo == delID)
	{
		// ȷ��ɾ����Ϣ
		printf("Delete the data of student:%d <y/n>?", delID);
		scanf("%c", &delChoice);
		if (delChoice == 'Y' || delChoice == 'y')
		{
			// ʹ��ɾ����Ϣ֮�����Ϣ������ǰ���ǣ� �ٽ�β�����
			while (++i < N)
			{
				tmpStud[i - 1] = tmpStud[i];
			}
			tmpStud[i - 1].sNo = 0;
			tmpStud[i - 1].sName[0] = '\0';
			tmpStud[i - 1].sSex = '\0';
			tmpStud[i - 1].sAddress[0] = '\0';
			printf("Complete!");
			getchar();
		}
	}
	else
	{
		// �Ҳ���ѧ�ţ� ��ӡ��ʾ��Ϣ
		printf("No data found!");
	}
	getchar();
}

void studentInfoEdit(studInfo *tmpStud)
{
	// ���Ա༭ѧ����Ϣ�ĺ���
	// �������Ҷ�����ر���
	system("CLS");
	int i, editID;
	char editChoice;
	studInfo tmpData;
	// ����ѧ��
	printf("Enter a student ID: ");
	scanf("%d", &editID);
	// ��������ѧ��
	for (i = 0; i < N && tmpStud[i].sNo != editID; i++);
	// �ж��Ƿ���ڸ�ѧ��
	if (tmpStud[i].sNo == editID)
	{
		// ���������뵽��ʱ������
		tmpData.sNo = editID;
		printf("Enter name: ");
		scanf("%s", tmpData.sName);
		printf("Enter sex: ");
		getchar();
		scanf("%c", &tmpData.sSex);
		printf("Enter address: ");
		scanf("%s", tmpData.sAddress);
		// ȷ���޸���Ϣ
		printf("Save changes <y/n>?");
		getchar();
		scanf("%c", &editChoice);
		if (editChoice == 'Y' || editChoice == 'y')
		{
			// �����ݴ���ʱ������ȡ��
			tmpStud[i] = tmpData;
			printf("Edit complete!");
		}
		else
		{
			printf("Press <Enter> to continue.");
		}
	}
	else
	{
		printf("No data found!");
	}
	getchar();
	getchar();
}

void studentInfoSort(studInfo *tmpStud)
{
	// ��������ĺ���
	// ð������
	int i, j;
	studInfo tmpData;
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - i - 1; j++)
		{
			if (tmpStud[j].sNo > tmpStud[j + 1].sNo && tmpStud[j + 1].sNo != 0)
			{
				tmpData = tmpStud[j];
				tmpStud[j] = tmpStud[j + 1];
				tmpStud[j + 1] = tmpData;
			}
		}
	}
	printf("Sort complete!");
	getchar();
	getchar();
}
