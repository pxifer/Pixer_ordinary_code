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
	Initboard(board, ROW, COL);//���̳�ʼ����
	Displayboard(board, ROW, COL);
	while (1)//���ֽ�֣�return*���Ӯ��return#����Ӯ��return0ƽ�֣�return1����Ϸ������
	{
		PlayerMove(board, ROW, COL);//�����*
		Displayboard(board, ROW, COL);//��ӡ���̣�
		ret=Is_win(board, ROW, COL);
	      Sleep(400);
		system("cls");
		if (ret != 1)
		{
			break;
		}

		ComputerMove(board, ROW, COL);//������#
		Displayboard(board, ROW, COL);//��ӡ���̣�
		ret=Is_win(board, ROW, COL);
		if (ret != 1)
		{
			break;
		}
	}
	if (ret == '*')
		printf("���Ӯ!\n");
	if (ret == '#')
		printf("����Ӯ!\n");
	if (ret == 0)
		printf("ƽ��!\n");
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
		printf("��ѡ��>:");
		scanf("%d", &input);
		Sleep(1000);
		system("cls");
	switch(input)
	{ 
	case 1:
		printf("������\n");
		Sleep(1000);
		system("cls");
		game();
		break;
	case 0:
		break;
		printf("�˳���Ϸ\n");
		Sleep(1000);
		system("cls");
		break;
	default:
		printf("ѡ�����\n������ѡ��\n");
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