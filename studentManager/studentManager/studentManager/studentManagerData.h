/*
	��������Ҫʹ�õ����ݽṹ����
	���ߣ�������
	�汾��1.0
*/

#ifndef STUDENTMANAGERDATA_H
#define STUDENTMANAGERDATA_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ������������Ϊ�ֱ���Ϊѧ����ѡ����Ϣ������
#define N 100
#define S 300

typedef struct studentInfo
{
	int sNo;
	char sName[40];
	char sSex;
	char sAddress[100];
}studInfo;

typedef struct courseInfo
{
	int cNo;
	char cName[80];
	int cCredit;
	int cTime;
	struct courseInfo *next;

}courInfo;

typedef struct resultInfo
{
	int sNo;
	char sName[40];
	int cNo;
	char cName[80];
	int sTerm;
	int score;
}resuInfo;

// Ϊ����ר�Ŵ���������
typedef struct rankInfo
{
	int sNo;
	char sName[40];
	float averScore;
}rankInfo;

#endif
