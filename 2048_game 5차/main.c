#include "game2048.h"

int board[SIZE][SIZE];

int main() {
    char userInput;
    bool isGameRunning = true;
    
    printf("Welcome to 2048!\n");
    printf("Goal: Combine tiles to reach 2048!\n");
    printf("Press any key to start...\n");
    getch();
    
    // Initialize the game
    initBoard();
    printBoard();
    
    // Main game loop
    while (isGameRunning) {
        printf("Your move: ");
        userInput = getch();
        
        // Convert to lowercase
        if (userInput >= 'A' && userInput <= 'Z') {
            userInput = userInput + 32;
        }
        
        switch (userInput) {
            case 'w':
                printf("UP\n");
                if (moveTiles(userInput)) {
                    printBoard();
                    if (checkGameOver()) {
                        isGameRunning = false;
                    }
                } else {
                    printf("Can't move up! Try another direction.\n");
                    printf("Press any key to continue...");
                    getch();
                    printBoard();
                }
                break;
                
            case 'a':
                printf("LEFT\n");
                if (moveTiles(userInput)) {
                    printBoard();
                    if (checkGameOver()) {
                        isGameRunning = false;
                    }
                } else {
                    printf("Can't move left! Try another direction.\n");
                    printf("Press any key to continue...");
                    getch();
                    printBoard();
                }
                break;
                
            case 's':
                printf("DOWN\n");
                if (moveTiles(userInput)) {
                    printBoard();
                    if (checkGameOver()) {
                        isGameRunning = false;
                    }
                } else {
                    printf("Can't move down! Try another direction.\n");
                    printf("Press any key to continue...");
                    getch();
                    printBoard();
                }
                break;
                
            case 'd':
                printf("RIGHT\n");
                if (moveTiles(userInput)) {
                    printBoard();
                    if (checkGameOver()) {
                        isGameRunning = false;
                    }
                } else {
                    printf("Can't move right! Try another direction.\n");
                    printf("Press any key to continue...");
                    getch();
                    printBoard();
                }
                break;
                
            case 'q':
                printf("\nThanks for playing 2048!\n");
                printf("Press any key to exit...");
                getch();
                isGameRunning = false;
                break;
                
            default:
                printf("Invalid key! Use W/A/S/D or Q\n");
                printf("Press any key to continue...");
                getch();
                printBoard();
                break;
        }
    }
    
    return 0;
}
