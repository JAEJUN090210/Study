#include "game2048.h"

bool checkGameOver() {
    // 1. Check for 2048 tile (win condition)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 2048) {
                printf("Congratulations! You reached 2048! You win!\n");
                return true;
            }
        }
    }
    
    // 2. Check for empty tiles
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                return false; // Game continues if there are empty tiles
            }
        }
    }
    
    // 3. Check for possible merges
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Check right neighbor
            if (j < SIZE - 1 && board[i][j] == board[i][j + 1]) {
                return false; // Can merge horizontally
            }
            // Check bottom neighbor
            if (i < SIZE - 1 && board[i][j] == board[i + 1][j]) {
                return false; // Can merge vertically
            }
        }
    }
    
    // No moves possible - game over
    printf("Game Over! No more moves possible.\n");
    return true;
}
