#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("---------------------------------\n");
	printf("-----1.��ʼ��Ϸ   0.�˳���Ϸ-----\n");
	printf("---------------------------------\n");
}
void game()
{
	//�����׵���Ϣ
	char mine[ROWS][COLS] = { 0 };
	//�Ų��׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//�ֱ𽫲��õĺ��Ų����Ϣ��ʼ��
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');
	DisplayBoard(mine,ROW,COL);
	//������
	SetMine(mine,ROW,COL);
	//ɨ��(��mine�������Ϣ�ҳ�����Ȼ��ŵ�show����)
	FindMine(mine, show,ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
		}
	} while (input);
	return 0;
}