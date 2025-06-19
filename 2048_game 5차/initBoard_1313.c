#include "game2048.h"

void initBoard() {
    // Initialize random seed
    srand((unsigned int)time(NULL));
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // 대각선에는 특별한 값 설정
            if (i == j) {
                board[i][j] = 0; // 대각선은 빈 칸으로
            } else if (i + j == SIZE - 1) {
                board[i][j] = 0; // 반대 대각선도 빈 칸으로
            } else {
                board[i][j] = 0; // 나머지도 빈 칸으로
            }
        }
    }
    
    // Generate 2 initial tiles
    generateTile();
    generateTile();
}
