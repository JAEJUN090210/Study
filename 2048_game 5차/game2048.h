#ifndef GAME2048_H
#define GAME2048_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>

#define SIZE 4
#define BOARD_SIZE 4
#define WIN_TILE 2048
#define INITIAL_TILE_COUNT 2

// Global game board
extern int board[SIZE][SIZE];

// Function declarations
void initBoard();
void generateTile();
bool moveTiles(char direction);
void mergeTiles(int line[SIZE]);
bool checkGameOver();
void printBoard();

#endif
