#include<stdio.h>
#include<time.h>	//ʹ�����е�time��Ϊ���������
#include<windows.h>	//�������е�Sleep����ʱ
#include<stdlib.h>	//�������е�rand�����������

#define  NUM 1000	//����һ��Ԥ�����������������������
#define GEN 30 //ѭ��ѡ�����

char bg[40][20];	//����һ����ά�����ṩ�ַ�����
int generation = 0;	//��ǰ�Ŵ��Ĵ���
int live;		//�����������
int s = 0;	 //������¼·��

struct creature		//����һ�����ʾ����
{
	char gene[9];	//��λ�ַ�����ʾ����
	int x;		//����λ�ú�����
	int y;		//����λ��������
	char step[61];	//���������ѡ���е�·����¼
	int alive;	//�ж������Ƿ���
}; 

struct creature cre[NUM];	//������������

void init();	//������������ʼ��
int sum(int a, int b);		//����������ͳ�ƻ���Ƶ��
int randmove(int c);		//�������������ȡ���ƶ�����
void refresh();		//����������ˢ����Ļ
void move(int c);	//���������� �ƶ�����
void run();	//���������� ѡ�����
void swap(int a, int b);		//���������� ��������λ�ã�����ĸ���������
void rank();	//���������� ����������
void dieout();	//������������Ȼѡ��ɱ��һ�������
void reproduce();		//�������������ܣ���ѡ���´���������з��ܣ���������������

int main()
{
	int a, b;		//ѭ���þֲ�����
	init();	//��ʼ��
	for (a = 0; a < GEN; a++)		//ѭ��ѡ��
	{
		run();	//����ѡ�����
		rank();	//��һ������Ϊ��̭��׼��
		dieout(); //��̭����������
		rank();	//�ڶ������� ��Ϊ������׼��
		reproduce(); //���з��ܺ���
		refresh();
	}
	getchar(); 
	return 0;
}

void init()
{
	int x, y, c, g;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = 0;
	SetConsoleCursorInfo(hOut, &cci);
	system("mode con cols=40 lines=21"); //����Ϊ���ع��͵������ڴ�С
	srand(time(NULL)); // �������������
	for (y = 0; y < 20; y++) //Ƕ��ѭ����ӡ�ַ�����
	{
		for (x = 0; x < 34; x++)
		{
			if (y == 0 || y == 19 || x == 0 || x == 39)
			{
				bg[x][y] = '#';
			}
			else
			{
				bg[x][y] = ' ';
			}
			printf("%c", bg[x][y]);
		}
		printf("\n");
	}
	for (c = 0; c < NUM; c++)	//������ʼ����������
	{
		cre[c].alive = 1;
		cre[c].x = 4;
		cre[c].y = 10;
		for (g = 0; g < 8; g++)
		{
			cre[c].gene[g] = rand() % 4 + 48;
		}
		for (g = 0; g < 60; g++)
		{
			cre[c].step[g] = '0';
		}
	}
}

int sum(int a, int b)
{
	int i, sum;
	sum = 0;
	for (i = 0; i < 8; i++)
	{
		sum = ((cre[a].gene[i] - 48) == b) ? (sum + 1) : sum;
	}	//ͳ������a�Ļ���bƵ�ʲ�����
	return sum;
}

void refresh()
{
	int x, y, c; //ѭ���þֲ�����
	y = 0;
	system("cls");
	live = 0;
	while (y < NUM)	//�������������
	{
		if (cre[y].alive == 1 || cre[y].alive == 2)
		{
			live++;
		}
		y++;
	}
	for (y = 0; y < 20; y++)	//���´�ӡ��ǰ��Ļ
	{
		for (x = 0; x < 40; x++)
		{
			bg[x][y] = ' ';
			for (c = 0; c < NUM; c++)
			{
				if (cre[c].x == x && cre[c].y == y)
				{
					bg[x][y] = 's';
				}
				else if (x == 0 || y == 0 || x == 39 || y == 19)
				{
					bg[x][y] = '#';
				}
				bg[39][10] = '$';
				bg[39][9] = '$';
				bg[39][11] = '$';
			}
			printf("%c", bg[x][y]);
		}
		printf("\n");
	}
	printf("Alive: %d  Generation: %d", live, generation);	//ʵʱ��ʾ���������������ǰ����
}

int randmove(int c)
{
	float ra, r, u, d, l;	//����������Լ������
	int re;	//����������Է��ؼ�����
	ra = rand() % 100;	//����һ��100���������
	u = sum(c, 0)  * 100/ 8;	//ȡ����0����Ƶ����Ϊ�����˶��ĸ���
	d = sum(c, 1) * 100/ 8;		//ȡ����1����Ƶ����Ϊ�����ƶ��ĸ���
	l = sum(c, 2)  * 100/ 8;		//ȡ����2����Ƶ����Ϊ�����ƶ��ĸ���
	r =100 -u -d -l;	//���ڻ�������Ĳ�׼ȷ�ԣ�Ϊ��ֹ���ָ���©����ȡ1 - �������ʵ�ֵΪ�����ƶ��ĸ���
	if (ra < u) re = 1;
	else if(ra < (u + d)) re = 2;
	else if (ra < (u + d + l)) re = 3;
	else re = 4;	//��������������ȡһ������ֵ
	return re;	//���ؽ�����ϣ��£����ҷֱ�Ϊ 1��2��3��4
}

void move(int c)
{
	cre[c].step[s] = '0';	//Ϊ���ﵱǰ�ƶ������һ��Ĭ��ֵ
	if (cre[c].alive == 1)	//�ж������Ƿ�����δ�������
	{
		switch (randmove(c))	//��������ƶ������ķ���ֵѡ���ƶ�����
		{
		case 1:
			if (bg[cre[c].x][cre[c].y - 1] != '#')		//�ж�ǰ���Ƿ�Ϊ�գ�����Ϊ�����һ���ж���ǽ�ڻ��ǳ��ڣ���ǽ���������������ǳ�����������״̬2����ͣ��λ���ṩ���ߵ��������ȼ���
			{
				if (bg[cre[c].x][cre[c].y - 1] == '$')
				{
					cre[c].alive = 2;
				}
				else
				{
					cre[c].y--;
					cre[c].step[s] = '1';
				}
			}
			else
			{
				cre[c].alive = 0;
			}
			break;
		case 2:
			if (bg[cre[c].x][cre[c].y + 1] != '#')
			{
				if (bg[cre[c].x][cre[c].y + 1] == '$')
				{
					cre[c].alive = 2;
				}
				else
				{
					cre[c].y++;
					cre[c].step[s] = '2';
				}
			}
			else
			{
				cre[c].alive = 0;
			}
			break;
		case 3:
			if (bg[cre[c].x - 1][cre[c].y] != '#')
			{
				if (bg[cre[c].x - 1][cre[c].y] == '$')
				{
					cre[c].alive = 2;
				}
				else
				{
					cre[c].x--;
					cre[c].step[s] = '3';
				}
			}
			else
			{
				cre[c].alive = 0;
			}
			break;
		case 4:
			if (bg[cre[c].x + 1][cre[c].y] != '#')
			{
				if (bg[cre[c].x + 1][cre[c].y] == '$')
				{
					cre[c].alive = 2;
				}
				else
				{
					cre[c].x++;
					cre[c].step[s] = '4';
				}
			}
			else
			{
				cre[c].alive = 0;
			}
			break;
		}
	}
}

void run()
{
	int a, b; //����ѭ���ñ���
	generation++; //ѡ�����+1
	s = 0;	//��ʼ��·����¼��㣬����Ҫ���粻��ʼ���ᵼ�����������ɳ������
	for (b = 0; b < NUM; b++)	// ��ʼ����������״̬���ָ�����ͣ��λ�������һ��·��
	{
		cre[b].alive = 1;
		for (a = 0; a < 60; a++)
		{
			cre[b].step[a] = '0';
		}
	}
	for(a = 0; a < 50; a = (live <= NUM / 2) ? 50 : a)	//ʹ�����漴�ƶ���ѭ��50�λ���������С�����ֵһ��ʱ��ֹѭ��
	{
		for (b = 0; b < NUM; b++) move(b);
		refresh();
		Sleep(50);
		a++;
		s++;	//·����¼����+1
	}
}

void swap(int a, int b)
{
	int v;
	char tgene[9];
	int tx;
	int ty;
	char tstep[61];
	int talive;
	//---------------------
	for (v = 0; v < 9; v++) //������a�ĸ������ݼ�¼����ʱ������
	{
		tgene[v] = cre[a].gene[v];
	}
	tx = cre[a].x;
	ty = cre[a].y;
	for (v = 0; v < 61; v++)
	{
		tstep[v] = cre[a].step[v];
	}
	talive = cre[a].alive;
	//---------------------
	for (v = 0; v < 9; v++)	//������b�����ݸ�������a
	{
		cre[a].gene[v] = cre[b].gene[v];
	}
	cre[a].x = cre[b].x;
	cre[a].y = cre[b].y;
	for (v = 0; v < 61; v++)
	{
		cre[a].step[v] = cre[b].step[v];
	}
	cre[a].alive = cre[b].alive;
	//-------------------------
	for (v = 0; v < 9; v++)	//����ʱ������ȡ������a�����ݸ�������b
	{
		cre[b].gene[v] = tgene[v];
	}
	cre[b].x =tx;
	cre[b].y = ty;
	for (v = 0; v < 61; v++)
	{
		cre[b].step[v] = tstep[v];
	}
	cre[b].alive = talive;
}

void dieout()
{
	int a;
	for (a = NUM / 2; a < NUM; a++) cre[a].alive = 0;
	for (a = 0; a <NUM / 20; a++)
	{
		cre[rand() % (NUM / 3) + NUM / 5].alive = 0;
		cre[rand() % (NUM / 3) + NUM / 2].alive = 1;
	}
}

void rank()
{
	int a,b, n1, n2, n3;
	n1 = 0;
	n2 = 0;
	n3 = 0;
	for (a = 0; a < NUM - 1 ; a++)	//��������״̬���г�������
	{
		for (b = 0; b < NUM  - a - 1; b++)
		{
			if (cre[b].alive < cre[b + 1].alive)
			{
				swap(b, b + 1);
			}
		}
	}
	for (a = 0; a <NUM; a++)	//ͳ�Ƹ���״̬�е�������Ŀ
	{
		n1 += (cre[a].alive == 2) ? 1 : 0;
		n2 += (cre[a].alive == 1) ? 1 : 0;
		n3 += (cre[a].alive == 0) ? 1 : 0;
	}
	for (a = 0; a < n1 - 1; a++)	//�Եִ��յ�����������������Ϊ���ò�����ԽСԽ��ǰ
	{
		for (b = 0; b < n1 - a - 1; b++)
		{
			int s1, s2, i;
			s1 = 0;
			s2 = 0;
			for (i = 0; i < 60; i++) if (cre[b].step[i] == '0') s1++;
			for (i = 0; i < 60; i++) if (cre[b + 1].step[i] == '0') s2++;
			if (s1 < s2) swap(b, b + 1);
		}
	}
	for (a = n1; a < n1 + n2 - 1; a++)	//��δ�ִ��յ㵫�Ǵ��ĵ�λ�������� ������xֵ��Խ�����ұ�Խ��ǰ
	{
		for (b = n1; b < n1 + n2 - a - 1; b++) if (cre[b].x < cre[b + 1].x) swap(b, b + 1);
	}
	for (a = n1+n2; a <NUM - 1 ; a++)		//��������λ������������ͬ�ϡ�
	{
		for (b = n1 + n2; b < NUM - 1 ; b++) if (cre[b].x < cre[b + 1].x) swap(b, b + 1);
	}
}

void reproduce()
{
	int a, b, t;		//����ѭ�������ʹ洢��ʱ���ݵı���
	live = 0;	//��ʼ�������������
	for (b = 0; b < NUM; b++) if (cre[b].alive != 0) live++;	//ͳ�ƴ����������
	while (live < NUM)	//Ϊ�������︳��������ֱ�����������״̬��Ϊ���
	{
		for (a = 0; a < NUM; a++)	//������������
		{
			cre[a].x = 4;	//��ʼ�����������λ��
			cre[a].y = 10;
			if (cre[a].alive == 0)		//�ж������Ƿ�����
			{
				for (b = 0; b < 8; b++)		//��������λ��ÿһλ������в���
				{
					t = rand() % NUM;	//���ȡһ������
					while (cre[t].alive == 0)
					{
						t = rand() % NUM;	//�ж�ѡȡ����Ĵ��״̬��ֱ��ѡȡ����������
					}
					cre[a].gene[b] = (rand() % 1000 == 122)? rand()%3 + 48 : cre[t].gene[b];	//����������λ�Ļ�����ǧ��֮һ�ĸ��ʷ����������
				}
				cre[a].alive = 1;	//��������λ�Ĵ��״̬��Ϊ���
				for (b = 0; b < NUM; b++) if (cre[b].alive != 0) live++;	//ͳ�ƴ�λ����Ŀ
			}
		}
	}
}