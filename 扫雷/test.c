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
	char show[ROWS][COLS] = { 0 };//���������ӡ����ֹӰ�죻

	initboard(mine, ROWS, COLS, '0');//�ڲ����ױ���ʼ����
	initboard(show, ROWS, COLS, '*');//�ⲿ��չʾ��

	Set_mine(mine, ROW, COL);
	displayboard(mine, ROW, COL);//��Ϸ������
	displayboard(show, ROW, COL);//��Ϸ����;

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
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}