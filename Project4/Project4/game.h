#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//使用全局变量
#define EASY_COUNT 10
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
//初始化棋盘
void initbroad(char board[ROWS][COLS], int rows, int cols, char set);
void disbroad(char board[ROWS][COLS], int row, int col);
void setbroad(char board[ROWS][COLS], int row, int col);
void findbroad(char mine[ROWS][COLS],int show[ROWS][COLS],int row,int col);
int get_mine_num(char mine[ROWS][COLS],int x, int y);
