#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"
void game() {
	char mine[ROWS][COLS] = { 0 };//���÷��õ���
	char show[ROWS][COLS] = { 0 };//����׵���Ϣ
	initbroad(mine, ROWS, COLS,'0');//ע�����ַ�''
	initbroad(show, ROWS, COLS, '*');
	disbroad(show, ROW, COL);
	setbroad(mine, ROW, COL);
	findbroad(mine, show, ROW, COL);
}
int main() {
	//��ѡ�����ж��Ƿ�����Ϸ
	int chooce = 0;
	srand((unsigned int)time(NULL));
	do {
		printf("���������ѡ��");
		scanf("%d", &chooce);
		switch (chooce) {
		case 1:
			printf("����������\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("��������ȷ��ѡ��");
			break;
		}
	} while (chooce);
	return 0;

}