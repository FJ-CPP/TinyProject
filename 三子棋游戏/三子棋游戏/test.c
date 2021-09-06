#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("***************************\n");
	printf("***1.开始游戏 0.退出游戏***\n");
	printf("***************************\n");
	printf("请输入数字1或0:");
}
void game()
{
	char r;
	char board[ROW][COL] = { 0 };
	//初始化棋盘（清空棋盘）
	Initboard(board, ROW, COL);
	//打印棋盘
	Displayboard(board, ROW, COL);
	//人机对弈
	while (1)
	{
		Player(board, ROW, COL);
		Displayboard(board, ROW, COL);
		r = Judge(board, ROW, COL);
		if (r != 'C')
			break;
		Computer(board, ROW, COL);
		Displayboard(board, ROW, COL);
		r = Judge(board, ROW, COL);
		if (r != 'C')
			break;
	}
	//判断输赢
	if (r == '*')
	{
		printf("玩家赢\n");
	}
	else if (r == '#')
	{
		printf("电脑赢\n");
	}
	else if (r == 'E')
	{
		printf("平局\n");
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请输入正确的选项\n");
			break;
		}
	} while (input);
	printf("游戏结束！");
	return 0;
}