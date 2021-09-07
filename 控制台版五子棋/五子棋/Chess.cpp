#define _CRT_SECURE_NO_WARNINGS 1
#include "Chess.h"
void Menu()
	{
	printf(" ------------------------------------- \n");
	printf("|<<<<<<<<<<<<<<<<������>>>>>>>>>>>>>>>|\n");
	printf("|<<<<<<<<<<<< ѡ���սģʽ >>>>>>>>>>>|\n");
	printf("|<<<<<<<<<<<< 1.PvP  2.PvE >>>>>>>>>>>|\n");
	printf("|<<<<<<<<<<<<  0.�˳���Ϸ  >>>>>>>>>>>|\n");
	printf("|<<<<<<<<<<<< ��ǰ�汾:1.0 >>>>>>>>>>>|\n");
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
{//x1y1�ǵ�ǰ���ӷ���һ�ε����꣬x2y2����һ����һ�ε�����
	if ((*ChessNum)>=2)
	{
		if (*Retract > 0)//���л�����������
		{
			board[x1-1][y1-1] = board[x2-1][y2-1] = ' ';
			*ChessNum -= 2;//����������2
			(*Retract)--;//ʣ���������1
			return 1;
		}
		else//û�л������
		{
			return 0;
		}
	}
	else
	{
		return -1;//�����ϵ���������֧�ֻ���
	}
}
bool CheckRow(int board[ROW][COL], int row, int col, int winnum)
{
	int i,j,k;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j <= col - winnum; j++)//ֻ���ж�1~11������0~10���������Ƿ���WIN_NUM������
		{
			int flag = 1;
			for (k = 0; k < winnum; k++)//�ж��Ƿ���������WIN_NUM��
			{
				if (board[i][j] != board[i][j + k])
				{
					flag = 0;
				}
			}
			if (flag == 1 && board[i][j]!=' ')//����� �ǿո�(������) ����
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
	for (i = 0; i <= row - winnum; i++)//ֻ���ж�1~11������0~10���������Ƿ���WIN_NUM������
	{
		for (j = 0; j < col; j++)
		{
			int flag = 1;
			for (k = 0; k < winnum; k++)//�ж��Ƿ���������WIN_NUM��
			{
				if (board[i][j] != board[i + k][j])
				{
					flag = 0;
				}
			}
			if (flag == 1 && board[i][j] != ' ')//����� �ǿո�(������) ����
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
	int WhiteRetract = 2;        //����ʣ��������
	int BlackRetract = 2;        //����ʣ��������
	int	ChessNum = 0;            //���µ���������
	InitBoard(board, ROW, COL);
	int x=0, y=0;//���浱ǰ��������
	int x_w=0, x_b=0, y_w=0, y_b=0;//������һ�ε���������
	//��Ϸ����
	while (1)
	{
		//�׷�����
		while (1)
		{
			PrintBoard(board, ROW, COL);//��ӡ����
			printf("��׷�'*'������������(����+�ո�+����<����0 0�ɻ���>)->");
			//������뻺����
			char clear;
			while ((clear = getchar()) != '\n')
			{
				;
			}
			scanf("%d%d", &x, &y);//��ȡ��������
			if (x == 0 && y == 0)//����
			{
				int ret = ChessRetract(board, x_w, y_w, x_b, y_b, &ChessNum,&WhiteRetract);
				if (ret == -1)
				{
					printf("��ǰ�޷�����!\n");
				}
				else
				{
					printf("�׷���ʣ%d�λ������\n", WhiteRetract);
					ChessNum -= 2;
				}
			}
			else
			{
				x_w = x;
				y_w = y;
				if (!(x_w >= 1 && x_w <= 15 && y_w >= 1 && y_w <= 15))//�Ƿ�����
				{
					printf("\n\n\t���겻�Ϸ�!(1��x,y��15)\n");
				}
				else if (board[x_w - 1][y_w - 1] != ' ')
				{
					printf("\n\n\t�˴��������ӣ���ѡ��հ״�����!\n");
				}
				else
				{
					board[x_w - 1][y_w - 1] = '*';
					ChessNum++;
					break;
				}
			}
		}
		//ƽ�����
		if (ChessNum == ROW * COL)
		{
			printf("ƽ��!\n");
			break;
		}
		PrintBoard(board, ROW, COL);//��ӡ����
		//�׷��������Ϸ���������׷�ʤ�����
		if (GameOver(board, ROW, COL))
		{
			printf("�׷�'*'ʤ!\n");
			break;
		}
		system("cls");
		//�ڷ�����
		while (1)
		{
			PrintBoard(board, ROW, COL);//��ӡ����
			printf("��ڷ�'#'������������(����+�ո�+����<����0 0�ɻ���>)->");
			//������뻺����
			char clear;
			while ((clear = getchar()) != '\n')
			{
				;
			}
			scanf("%d%d", &x, &y);//��ȡ����
			if (x == 0 && y == 0)//����
			{
				int ret = ChessRetract(board, x_b, y_b, x_w, y_w, &ChessNum, &BlackRetract);
				if (ret == -1)
				{
					printf("��ǰ�޷�����!\n");
				}
				else
				{
					printf("�ڷ���ʣ%d�λ������\n", BlackRetract);
					ChessNum -= 2;
				}
			}
			else
			{
				x_b = x;
				y_b = y;
				if (!(x_b >= 1 && x_b <= 15 && y_b >= 1 && y_b <= 15))//�Ƿ�����
				{
					printf("\n\n\t���겻�Ϸ�!(1��x,y��15)\n");
				}
				else if (board[x_b - 1][y_b - 1] != ' ')
				{
					printf("\n\n\t�˴��������ӣ���ѡ��հ״�����!\n");
				}
				else
				{
					board[x_b - 1][y_b - 1] = '#';
					ChessNum++;
					break;
				}
			}
		}
		PrintBoard(board, ROW, COL);//��ӡ����
		//�׷��������Ϸ���������׷�ʤ�����
		if (GameOver(board, ROW, COL))
		{
			printf("�ڷ�'#'ʤ!\n");
			break;
		}
		system("cls");
	}
}