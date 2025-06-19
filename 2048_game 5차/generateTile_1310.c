#include "game2048.h"

void generateTile() {
    int emptyTiles[SIZE * SIZE][2]; // Store coordinates of empty tiles
    int emptyCount = 0;
    
    // 1. Find all empty tiles
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                emptyTiles[emptyCount][0] = i;
                emptyTiles[emptyCount][1] = j;
                emptyCount++;
            }
        }
    }
    
    // 2. If no empty tiles, return
    if (emptyCount == 0) return;
    
    // 3. Select random empty tile
    int randomIndex = rand() % emptyCount;
    int x = emptyTiles[randomIndex][0];
    int y = emptyTiles[randomIndex][1];
    
    // 4. Generate tile: 90% chance for 2, 10% chance for 4
    int tileValue = (rand() % 10 == 0) ? 4 : 2;
    board[x][y] = tileValue;
}
