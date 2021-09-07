#define _CRT_SECURE_NO_WARNINGS 1
#include "Chess.h"
void Menu()
	{
	printf(" ------------------------------------- \n");
	printf("|<<<<<<<<<<<<<<<<五子棋>>>>>>>>>>>>>>>|\n");
	printf("|<<<<<<<<<<<< 选择对战模式 >>>>>>>>>>>|\n");
	printf("|<<<<<<<<<<<< 1.PvP  2.PvE >>>>>>>>>>>|\n");
	printf("|<<<<<<<<<<<<  0.退出游戏  >>>>>>>>>>>|\n");
	printf("|<<<<<<<<<<<< 当前版本:1.0 >>>>>>>>>>>|\n");
	printf(" ------------------------------------- \n");
}
void InitBoard(int board[ROW][COL],int row,int col)
{	
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void PrintBoard(int board[ROW][COL],int row,int col)
{
	int i, j;
	for (i = 0; i < col; i++)
	{
		if (i == 0)
		{
			printf(" ");
		}
	    printf(" %2d ", i+1);
	}
	putchar('\n');
	for (i = 0; i < row; i++)
	{
		printf("%-2d", i + 1);
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j != col - 1)
			{
				putchar('|');
			}
		}
		putchar('\n');
		if (i != row - 1)
		{
			for (j = 0; j < col; j++)
			{
				if (j == 0)
				{
					printf("  ");
				}
				printf("---");
				if (j != col - 1)
				{
					putchar('|');
				}
			}
		}
		putchar('\n');
	}
}
bool GameOver(int board[ROW][COL], int row, int col)
{
	if (CheckRow(board, row, col, WINNUM))
	{
		return true;
	}
	if (CheckCol(board, row, col, WINNUM))
	{
		return true;
	}
	if (CheckLSlash(board, row, col, WINNUM))
	{
		return true;
	}
	if (CheckRSlash(board, row, col, WINNUM))
	{
		return true;
	}
	return false;
}
int ChessRetract(int board[ROW][COL], int x1, int y1, int x2, int y2, int* ChessNum, int* Retract)
{//x1y1是当前落子方上一次的坐标，x2y2是另一方上一次的坐标
	if ((*ChessNum)>=2)
	{
		if (*Retract > 0)//还有悔棋次数的情况
		{
			board[x1-1][y1-1] = board[x2-1][y2-1] = ' ';
			*ChessNum -= 2;//总落棋数减2
			(*Retract)--;//剩余悔棋数减1
			return 1;
		}
		else//没有悔棋次数
		{
			return 0;
		}
	}
	else
	{
		return -1;//棋盘上的落子数不支持悔棋
	}
}
bool CheckRow(int board[ROW][COL], int row, int col, int winnum)
{
	int i,j,k;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j <= col - winnum; j++)//只需判断1~11【数组0~10】列往后是否有WIN_NUM个连续
		{
			int flag = 1;
			for (k = 0; k < winnum; k++)//判断是否有连续的WIN_NUM个
			{
				if (board[i][j] != board[i][j + k])
				{
					flag = 0;
				}
			}
			if (flag == 1 && board[i][j]!=' ')//有五个 非空格(即棋子) 连续
			{
				return true;
			}
		}
	}
	return false;
}
bool CheckCol(int board[ROW][COL], int row, int col, int winnum)
{
	int i, j, k;
	for (i = 0; i <= row - winnum; i++)//只需判断1~11【数组0~10】行往下是否有WIN_NUM个连续
	{
		for (j = 0; j < col; j++)
		{
			int flag = 1;
			for (k = 0; k < winnum; k++)//判断是否有连续的WIN_NUM个
			{
				if (board[i][j] != board[i + k][j])
				{
					flag = 0;
				}
			}
			if (flag == 1 && board[i][j] != ' ')//有五个 非空格(即棋子) 连续
			{
				return true;
			}
		}
	}
	return false;
}
bool CheckLSlash(int board[ROW][COL], int row, int col, int winnum)
{
	int i, j, k;
	for (i = winnum - 1; i < row; i++)
	{
		for (j = 0; j < col - winnum; j++)
		{
			int flag = 1;
			for (k = 0; k < winnum; k++)
			{
				if (board[i][j] == ' ' || board[i][j] != board[i - k][j + k])
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				return true;
			}
		}
	}
	return false;
}
bool CheckRSlash(int board[ROW][COL], int row, int col, int winnum)
{
	int i, j, k;
	for (i = 0; i < row - winnum; i++)
	{
		for (j = 0; j < col - winnum; j++)
		{
			int flag = 1;
			for (k = 0; k < winnum; k++)
			{
				if (board[i][j] == ' ' || board[i][j] != board[i + k][j + k])
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				return true;
			}
		}
	}
	return false;
}
void GamePVP()
{
	int board[ROW][COL];
	int WhiteRetract = 2;        //白棋剩余悔棋次数
	int BlackRetract = 2;        //黑棋剩余悔棋次数
	int	ChessNum = 0;            //已下的棋子总数
	InitBoard(board, ROW, COL);
	int x=0, y=0;//保存当前落子坐标
	int x_w=0, x_b=0, y_w=0, y_b=0;//保存上一次的落子坐标
	//游戏部分
	while (1)
	{
		//白方落子
		while (1)
		{
			PrintBoard(board, ROW, COL);//打印棋盘
			printf("请白方'*'输入落子坐标(数字+空格+数字<输入0 0可悔棋>)->");
			//清空输入缓冲区
			char clear;
			while ((clear = getchar()) != '\n')
			{
				;
			}
			scanf("%d%d", &x, &y);//读取白子坐标
			if (x == 0 && y == 0)//悔棋
			{
				int ret = ChessRetract(board, x_w, y_w, x_b, y_b, &ChessNum,&WhiteRetract);
				if (ret == -1)
				{
					printf("当前无法悔棋!\n");
				}
				else
				{
					printf("白方还剩%d次悔棋机会\n", WhiteRetract);
					ChessNum -= 2;
				}
			}
			else
			{
				x_w = x;
				y_w = y;
				if (!(x_w >= 1 && x_w <= 15 && y_w >= 1 && y_w <= 15))//非法坐标
				{
					printf("\n\n\t坐标不合法!(1≤x,y≤15)\n");
				}
				else if (board[x_w - 1][y_w - 1] != ' ')
				{
					printf("\n\n\t此处已有棋子，请选择空白处落子!\n");
				}
				else
				{
					board[x_w - 1][y_w - 1] = '*';
					ChessNum++;
					break;
				}
			}
		}
		//平局情况
		if (ChessNum == ROW * COL)
		{
			printf("平局!\n");
			break;
		}
		PrintBoard(board, ROW, COL);//打印棋盘
		//白方下完后游戏结束，即白方胜的情况
		if (GameOver(board, ROW, COL))
		{
			printf("白方'*'胜!\n");
			break;
		}
		system("cls");
		//黑方落子
		while (1)
		{
			PrintBoard(board, ROW, COL);//打印棋盘
			printf("请黑方'#'输入落子坐标(数字+空格+数字<输入0 0可悔棋>)->");
			//清空输入缓冲区
			char clear;
			while ((clear = getchar()) != '\n')
			{
				;
			}
			scanf("%d%d", &x, &y);//读取坐标
			if (x == 0 && y == 0)//悔棋
			{
				int ret = ChessRetract(board, x_b, y_b, x_w, y_w, &ChessNum, &BlackRetract);
				if (ret == -1)
				{
					printf("当前无法悔棋!\n");
				}
				else
				{
					printf("黑方还剩%d次悔棋机会\n", BlackRetract);
					ChessNum -= 2;
				}
			}
			else
			{
				x_b = x;
				y_b = y;
				if (!(x_b >= 1 && x_b <= 15 && y_b >= 1 && y_b <= 15))//非法坐标
				{
					printf("\n\n\t坐标不合法!(1≤x,y≤15)\n");
				}
				else if (board[x_b - 1][y_b - 1] != ' ')
				{
					printf("\n\n\t此处已有棋子，请选择空白处落子!\n");
				}
				else
				{
					board[x_b - 1][y_b - 1] = '#';
					ChessNum++;
					break;
				}
			}
		}
		PrintBoard(board, ROW, COL);//打印棋盘
		//白方下完后游戏结束，即白方胜的情况
		if (GameOver(board, ROW, COL))
		{
			printf("黑方'#'胜!\n");
			break;
		}
		system("cls");
	}
}