#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#define ROW        15    //��������
#define COL        15    //��������
#define WINNUM    5     //Ӯ���׼
enum//�˵���
{
	Over,
	PvP,
	PvE
};

void Menu();//��ӡ�˵�
void GamePVP();
void InitBoard(int board[ROW][COL], int row, int col);//��ʼ������
void PrintBoard(int board[ROW][COL], int row, int col);//��ӡ����
bool GameOver(int board[ROW][COL], int row, int col);//�ж���Ӯ
bool CheckRow(int board[ROW][COL], int row, int col, int winnum);//�ж����Ƿ����������
bool CheckCol(int board[ROW][COL], int row, int col, int winnum);//�ж����Ƿ����������
bool CheckLSlash(int board[ROW][COL], int row, int col, int winnum);//�ж�'\'�����Ƿ����������
bool CheckRSlash(int board[ROW][COL], int row, int col, int winnum);//�ж�'/'�����Ƿ����������
int ChessRetract(int board[ROW][COL], int x1, int y1, int x2, int y2,int* ChessNum,int* Retract);//����