#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void initbroad(char board[ROWS][COLS], int rows, int cols, char set) {
	int i = 0;
	for (i = 0; i < rows; i++) {
		int j = 0;
		for (j = 0; j < cols; j++) {
			board[i][j] = set;
		}
	}
}
void disbroad(char board[ROWS][COLS], int row, int col) {
	for (int k = 0; k <= row; k++) {
		printf("%d ", k);
	}
	printf("\n");
	for (int i = 1; i <= row; i++) {
		printf("%d ", i);
		for (int j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void setbroad(char board[ROWS][COLS], int row, int col) {
	int count = EASY_COUNT;
	while (count) {
		int x = rand() % ROW + 1;
		int y = rand() % COL + 1;
		if (board[x][y] == '0') {
			board[x][y] = '1';
			count--;
		}
	}
}
int get_mine_num(char mine[ROWS][COLS], int x, int y) {
	return (mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y -1] 
		+ mine[x + 1][y] +mine[x + 1][y + 1] + mine[x][y + 1]
		+ mine[x - 1][y + 1] - 8 * '0');
}
void findbroad(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < (row * col - EASY_COUNT)) {
		printf("请输入你要排查的坐标: ");
		scanf("%d%d", &x, &y);
		if (show[x][y] != '*') {
			printf("该坐标以及被查过了");
			continue;
		}
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (mine[x][y] == '1') { 
				printf("很遗憾，你被炸死了\n");
				disbroad(mine, ROW, COL);
				return; 
			}
			else {
				int count = get_mine_num(mine, x, y);
				show[x][y] = count + '0';
				disbroad(show, ROW, COL);
				win++;
			}
		}
		else {
			printf("坐标错误，请重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT) {
		printf("恭喜你，排雷成功\n");
		disbroad(mine, ROW, COL); // 显示雷区
	}
}