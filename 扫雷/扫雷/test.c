#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("---------------------------------\n");
	printf("-----1.开始游戏   0.退出游戏-----\n");
	printf("---------------------------------\n");
}
void game()
{
	//布置雷的信息
	char mine[ROWS][COLS] = { 0 };
	//排查雷的信息
	char show[ROWS][COLS] = { 0 };
	//分别将布置的和排查的信息初始化
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');
	DisplayBoard(mine,ROW,COL);
	//布置雷
	SetMine(mine,ROW,COL);
	//扫雷(把mine数组的信息找出来，然后放到show数组)
	FindMine(mine, show,ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
		}
	} while (input);
	return 0;
}