/*
	��������������ͷ�ļ��������������ļ����
	���ߣ�������
	�汾��1.1
*/

#ifndef STUDENTMANAGERTOOLS_H
#define STUDENTMANAGERTOOLS_H
// ��ӡ���˵�
extern void mainMenu();
// ʵ�ֳ�ʼ���Լ����ݶ�д���ܣ� �����ļ�initAndLoadSave.c
extern void initInfo(studInfo*, courInfo*, resuInfo*);
extern void loadData(studInfo*, courInfo*, resuInfo*);
extern void saveData(studInfo*, courInfo*, resuInfo*);
//�������ģ��
extern void studentInfoManager(studInfo *);
extern void courseInfoManager(courInfo **);
extern void resultInfoManager(studInfo *, courInfo*, resuInfo*);
extern void scoreInfoManager(resuInfo *);
extern void infoSearchManager(studInfo*, courInfo*, resuInfo*);

#endif