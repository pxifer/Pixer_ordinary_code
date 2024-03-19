#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("*****************************\n");
	printf("********1.play 0.exit********\n");
	printf("*****************************\n");
}
void game()
{
	char ret = 'a';
	char board[ROW][COL] = { 0 };
	Initboard(board, ROW, COL);//棋盘初始化；
	Displayboard(board, ROW, COL);
	while (1)//四种结局：return*玩家赢；return#电脑赢；return0平局；return1；游戏继续；
	{
		PlayerMove(board, ROW, COL);//玩家用*
		Displayboard(board, ROW, COL);//打印棋盘；
		ret=Is_win(board, ROW, COL);
	      Sleep(400);
		system("cls");
		if (ret != 1)
		{
			break;
		}

		ComputerMove(board, ROW, COL);//电脑用#
		Displayboard(board, ROW, COL);//打印棋盘；
		ret=Is_win(board, ROW, COL);
		if (ret != 1)
		{
			break;
		}
	}
	if (ret == '*')
		printf("玩家赢!\n");
	if (ret == '#')
		printf("电脑赢!\n");
	if (ret == 0)
		printf("平局!\n");
	Sleep(1000);
	system("cls");

}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		Sleep(1000);
		system("cls");
	switch(input)
	{ 
	case 1:
		printf("三子棋\n");
		Sleep(1000);
		system("cls");
		game();
		break;
	case 0:
		break;
		printf("退出游戏\n");
		Sleep(1000);
		system("cls");
		break;
	default:
		printf("选择错误\n请重新选择！\n");
		Sleep(1000);
		system("cls");
		break;
	}
	} while (input);


}



int main()
{
	
	test();
	return 0;
}