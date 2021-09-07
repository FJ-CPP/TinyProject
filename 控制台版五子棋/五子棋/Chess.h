#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#define ROW        15    //棋盘行数
#define COL        15    //棋盘列数
#define WINNUM    5     //赢棋标准
enum//菜单项
{
	Over,
	PvP,
	PvE
};

void Menu();//打印菜单
void GamePVP();
void InitBoard(int board[ROW][COL], int row, int col);//初始化棋盘
void PrintBoard(int board[ROW][COL], int row, int col);//打印棋盘
bool GameOver(int board[ROW][COL], int row, int col);//判断输赢
bool CheckRow(int board[ROW][COL], int row, int col, int winnum);//判断行是否有五个连续
bool CheckCol(int board[ROW][COL], int row, int col, int winnum);//判断列是否有五个连续
bool CheckLSlash(int board[ROW][COL], int row, int col, int winnum);//判断'\'方向是否有五个连续
bool CheckRSlash(int board[ROW][COL], int row, int col, int winnum);//判断'/'方向是否有五个连续
int ChessRetract(int board[ROW][COL], int x1, int y1, int x2, int y2,int* ChessNum,int* Retract);//悔棋