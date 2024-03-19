#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("***************************\n");
	printf("*******    1.play   *******\n");
	printf("*******    0.exit   *******\n");
	printf("***************************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };//分离雷与打印，防止影响；

	initboard(mine, ROWS, COLS, '0');//内部含雷表；初始化；
	initboard(show, ROWS, COLS, '*');//外部件展示表；

	Set_mine(mine, ROW, COL);
	displayboard(mine, ROW, COL);//游戏雷区；
	displayboard(show, ROW, COL);//游戏界面;

	Find_mine(mine,show, ROWS, COLS);

	

}

void test()
{
	int input=0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}