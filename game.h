#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ROW 10
#define COL 10

#define PLAYER1 1
#define PLAYER2 2

#define NEXT 0

#define PLAYER1_WIN 1
#define PLAYER2_WIN 2
#define DRAW		3

enum Dir{
    LEFT,
    RIGHT,
    UP,
    DOWN,
    LEFT_UP,
    RIGHT_DOWN,
    RIGHT_UP,    
    LEFT_DOWN
};

void Menu();

void Game();

int isOver(int board[][COL], int row, int col);

void ShowBoard(int board[][COL],int row, int col);

int ChessCount(int board[][COL], enum Dir d);

void PlayerMove(int board[][COL], int p);
