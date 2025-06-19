#include "game2048.h"

void printBoard() {
    system("cls");

    printf("\n===== 2048 Game =====\n");
    printf("Goal: Combine tiles to reach 2048!\n\n");
    
    printf("+----+----+----+----+\n");
    
    for (int i = 0; i < SIZE; i++) {
        printf("|");
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                printf("    |");
            } else {
                printf("%4d|", board[i][j]);
            }
        }
        printf("\n");
        
        if (i < SIZE - 1) {
            printf("+----+----+----+----+\n");
        }
    }
    printf("+----+----+----+----+\n\n");
    
    printf("Controls: W(UP) A(LEFT) S(DOWN) D(RIGHT) Q(QUIT)\n");
    printf("Press any key to move (no Enter needed!)\n\n");
}
