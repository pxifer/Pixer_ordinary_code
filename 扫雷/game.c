#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void initboard(char board[ROWS][COLS], int row, int col, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}

void displayboard(char board[ROWS][COLS],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
		printf("%d ", i);
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
			printf("%c ", board[i][j]);
		printf("\n");
	}
}

void Set_mine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
	    int y = rand() % col + 1;

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	int i = 0, j = 0;
	int count = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
			count += mine[i][j] - '0';
	}
	return count;
}

void expand(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y,int *win)
{
	int i = 0;
	int j = 0;
	(*win)++;
	if (get_mine_count(mine,x,y) == 0)
	{
		show[x][y] ='#';

		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				if (show[i][j]=='*' && i >= 1 && i <= row && j >= 1 && j <= col)
				{
					expand(mine, show, ROW, COL, i, j, &win);
				}
			}
		}
	}
	else
	{
		show[x][y] = get_mine_count(mine, x, y) + '0';
	}
}

void Find_mine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col)
{
	int i=0, j=0;
	int x = 0, y = 0;
	int all = ROW * COL - EASY_COUNT;
	static int win = 0;
	while (win < all)
	{
		printf("请输入坐标\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if (mine[x][y] == '1')
			{
				printf("你已失败，点雷\n");
				displayboard(mine, ROW, COL);
				break;
			}
			else
			{
				expand(mine, show, ROW, COL, x, y,&win);
				displayboard(show, ROW, COL);
			}
		}
		else
			printf("地址不合法，请重新输入！\n");
	}
	if (win == all)
	{
		printf("你赢了游戏！\n");
		displayboard(mine, ROW, COL);
	}
	
}
