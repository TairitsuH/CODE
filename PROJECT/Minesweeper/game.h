#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define MINE 10


void InitBoard(char board[ROWS][COLS], int row, int col, char set); //初始化棋盘

void DisplayBoard(char board[ROWS][COLS], int row, int col); //打印棋盘

void SetMine(char mine[ROWS][COLS], int row, int col); //布置雷

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col); //排查雷