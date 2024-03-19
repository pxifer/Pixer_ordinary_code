#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
//ÉùÃ÷
void Initboard(char board[ROW][COL], int row, int col);
void Displayboard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(Is_win);
int Is_win(char board[ROW][COL], int row, int col);
int Is_full(char board[ROW][COL], int row, int col);