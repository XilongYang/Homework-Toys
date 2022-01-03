/*
	������ģ�飬�������Գ�ʼ���ṹ�壬��ȡ���ݺʹ������ݵĺ���
	���ߣ�������
	�汾��1.0
*/

#include "studentManagerData.h"

void initInfo(studInfo *tmpStudent, courInfo *headCourse, resuInfo *tmpResult)
{
	// ���Գ�ʼ���ṹ��ĺ���
	int i;
	// ������ѧ����Ϣ��ʼ��
	for (i = 0; i < N; i++)
	{
		tmpStudent[i].sNo = 0;
		tmpStudent[i].sName[0] = '\0';
		tmpStudent[i].sSex = '\0';
		tmpStudent[i].sAddress[0] = '\0';
	}
	// ��ʼ������ͷ�ڵ�
	headCourse->cNo = 0;
	headCourse->cName[0] = '\0';
	headCourse->cCredit = 0;
	headCourse->cTime = 0;
	headCourse->next = NULL;
	// �����гɼ���Ϣ��ʼ��
	for (i = 0; i < S; i++)
	{
		tmpResult[i].sNo = 0;
		tmpResult[i].sName[0] = '\0';
		tmpResult[i].cNo = 0;
		tmpResult[i].cName[0] = '\0';
		tmpResult[i].sTerm = 0;
		tmpResult[i].score = 0;

	}
}

void loadData(studInfo *tmpStudent, courInfo *tmpHeadCourse, resuInfo *tmpResult)
{
	// ���Դ��ļ��ж�ȡ���ݵĺ���
	int i;
	courInfo *tmpCurrentCourse, *tmpEndCourse;
	FILE *tmpStudentData, *tmpCourseData, *tmpResultData;
	// ��ab+���ļ��� ���ļ����������½�
	// ѧ����Ϣ��ȡ
	if ((tmpStudentData = fopen("student.dat", "ab+")) == NULL)
	{
		printf("Open file \"student.dat\" failed!");
		exit(0);
	}
	for (i = 0; i < N; i++)
	{
		if (0 == fread(&tmpStudent[i], sizeof(studInfo), 1, tmpStudentData))
		{
			break;
		}
	}
	fclose(tmpStudentData);
	// �γ���Ϣ��ȡ
	if ((tmpCourseData = fopen("course.dat", "ab+")) == NULL)
	{
		printf("Open file \"course.dat\" failed!");
		exit(0);
	}
	tmpEndCourse = tmpHeadCourse;
	while (1 == fread(tmpEndCourse, sizeof(courInfo), 1, tmpCourseData) && tmpEndCourse->next != NULL)
	{
		tmpCurrentCourse = (courInfo*)malloc(sizeof(courInfo));
		tmpEndCourse->next = tmpCurrentCourse;
		tmpEndCourse = tmpCurrentCourse;
	}
	tmpEndCourse->next = NULL;
	fclose(tmpCourseData);
	// �ɼ���Ϣ��ȡ
	if ((tmpResultData = fopen("result.dat", "ab+")) == NULL)
	{
		printf("Open file \"result.dat\" failed!");
		exit(0);
	}
	for (i = 0; i < S; i++)
	{
		if (0 == fread(&tmpResult[i], sizeof(resuInfo), 1, tmpResultData))
		{
			break;
		}
	}
	fclose(tmpResultData);
}

void saveData(studInfo *tmpStudent, courInfo *tmpHeadCourse, resuInfo *tmpResult)
{
	// �������ļ��б������ݵĺ���
	FILE *tmpStudentData, *tmpCourseData, *tmpResultData;
	// ʹ��wb���и���д��
	// ѧ����Ϣ�洢
	if ((tmpStudentData = fopen("student.dat", "wb")) == NULL)
	{
		printf("Open file \"student.dat\" failed!");
		exit(0);
	}
	fwrite(tmpStudent, sizeof(studInfo), N, tmpStudentData);
	fclose(tmpStudentData);
	// �γ���Ϣд��
	if ((tmpCourseData = fopen("Course.dat", "wb")) == NULL)
	{
		printf("Open file \"course.dat\" failed!");
		exit(0);
	}
	while (tmpHeadCourse != NULL)
	{
		fwrite(tmpHeadCourse, sizeof(courInfo), 1, tmpCourseData);
		tmpHeadCourse = tmpHeadCourse->next;
	}
	fclose(tmpStudentData);
	// �ɼ���Ϣд��
	if ((tmpResultData = fopen("result.dat", "wb")) == NULL)
	{
		printf("Open file \"result.dat\" failed!");
		exit(0);
	}
	fwrite(tmpResult, sizeof(resuInfo), S, tmpResultData);
	fclose(tmpResultData);
}