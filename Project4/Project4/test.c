#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"
void game() {
	char mine[ROWS][COLS] = { 0 };//布置放置的雷
	char show[ROWS][COLS] = { 0 };//存放雷的信息
	initbroad(mine, ROWS, COLS,'0');//注意是字符''
	initbroad(show, ROWS, COLS, '*');
	disbroad(show, ROW, COL);
	setbroad(mine, ROW, COL);
	findbroad(mine, show, ROW, COL);
}
int main() {
	//做选择来判断是否玩游戏
	int chooce = 0;
	srand((unsigned int)time(NULL));
	do {
		printf("请输入你的选择");
		scanf("%d", &chooce);
		switch (chooce) {
		case 1:
			printf("启动！！！\n");
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("请输入正确的选择");
			break;
		}
	} while (chooce);
	return 0;

}