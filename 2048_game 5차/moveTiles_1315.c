#include "game2048.h"

bool moveTiles(char direction) {
    int backup[SIZE][SIZE];
    bool moved = false;
    
    // Create backup of current board state
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            backup[i][j] = board[i][j];
        }
    }
    
    // Process each row/column based on direction
    for (int i = 0; i < SIZE; i++) {
        int line[SIZE];
        
        switch (direction) {
            case 'a': // Move left
                for (int j = 0; j < SIZE; j++) {
                    line[j] = board[i][j];
                }
                mergeTiles(line);
                for (int j = 0; j < SIZE; j++) {
                    board[i][j] = line[j];
                }
                break;
                
            case 'd': // Move right
                for (int j = 0; j < SIZE; j++) {
                    line[j] = board[i][SIZE - 1 - j];
                }
                mergeTiles(line);
                for (int j = 0; j < SIZE; j++) {
                    board[i][SIZE - 1 - j] = line[j];
                }
                break;
                
            case 'w': // Move up
                for (int j = 0; j < SIZE; j++) {
                    line[j] = board[j][i];
                }
                mergeTiles(line);
                for (int j = 0; j < SIZE; j++) {
                    board[j][i] = line[j];
                }
                break;
                
            case 's': // Move down
                for (int j = 0; j < SIZE; j++) {
                    line[j] = board[SIZE - 1 - j][i];
                }
                mergeTiles(line);
                for (int j = 0; j < SIZE; j++) {
                    board[SIZE - 1 - j][i] = line[j];
                }
                break;
                
            default:
                return false;
        }
    }
    
    // Check if board changed (inline isDifferent logic)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (backup[i][j] != board[i][j]) {
                moved = true;
                break;
            }
        }
        if (moved) break;
    }
    
    if (moved) {
        generateTile();
    }
    
    return moved;
}
