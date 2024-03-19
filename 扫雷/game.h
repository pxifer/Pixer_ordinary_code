#define ROWS 11
#define COLS 11

#define ROW 9
#define COL 9

#define EASY_COUNT 10

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void initboard(char board[ROWS][COLS], int row, int col, char set);
void displayboard(char board[ROWS][COLS], int row, int col);
void Set_mine(char board[ROWS][COLS], int row, int col);
void Find_mine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);

void expand(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col,int x,int y,int* win);

int get_mine_count(char mine[ROWS][COLS], int x, int y);

