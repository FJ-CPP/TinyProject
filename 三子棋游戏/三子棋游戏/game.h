#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

//º¯ÊýÉùÃ÷
void Initboard(char board[ROW][COL], int row, int col);
void Displayboard(char board[ROW][COL], int row, int col);
Player(char board[ROW][COL], int row, int col);
Computer(char board[ROW][COL], int row, int col);
char Judge(char board[ROW][COL], int row, int col);