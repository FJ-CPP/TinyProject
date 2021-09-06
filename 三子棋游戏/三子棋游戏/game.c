#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void Initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
}
//棋盘
// x | x | x 
//---|---|---
// x | x | x 
//---|---|---
// x | x | x 
void Displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		//打印一行数据
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//打印分隔行
		if(i<row-1)
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		printf("\n");
	}
}
 Player(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = 0;
		int y = 0;
		printf("请输入你的棋子坐标（如第一行第一列为1 1）：\n");
		scanf("%d%d", &x, &y);
		if (x <= row  && x >= 1 && y <= col && y >= 1)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该处已有棋子，请重新输入\n");
				continue;
			}
		}
		else
			printf("坐标范围错误,请重新输入");
	}
}
 Computer(char board[ROW][COL], int row, int col)
 {
	 int x = 0;
	 int y = 0;
	 while (1)
	 {
		 x = rand() % ROW;
		 y = rand() % COL;
		 if (board[x][y] == ' ')
		 {
			 board[x][y] = '#';
			 break;
		 }
	 }
 }
 int IsFull(char board[ROW][COL], int row, int col)//返回1表示棋盘已满，0表示棋盘没满
 {
	 int i, j;
	 for (i = 0; i < row; i++)
	 {
		 for (j = 0; j < col; j++)
			 if (board[i][j] == ' ')
				 return 0;
	 } 
	 return 1;
 }

 char Judge(char board[ROW][COL], int row,int col)
 {
	 int i = 0;
	 //行有三个相连的情况
	 for (i = 0; i < row; i++)
	 {
		 if (board[i][0] == board[i][1] && board[i][1]==
			 board[i][2] && board[i][0] != ' ')
			 return board[i][0];
	 }
	 //列有三个相连的情况
	 for (i = 0; i < col; i++)
	 {
		 if (board[0][i] == board[1][i] && board[1][i]==
			 board[2][i] && board[0][i] != ' ')
			 return board[0][i];
	 }
	 //对角线三个相连的情况
	 if (board[0][0] == board[1][1]&& board[1][1]==board[2][2]&&board[0][0]!=' '
		 || board[0][2] == board[1][1]&&board[1][1] == board[2][0]&&board[0][2] != ' ')
		 return board[1][1];
	 //平局的情况（棋盘满了）
	 if  (IsFull( board , ROW,COL) ==1)
	 {
		 return 'E';
	 }
	 return 'C';
 }