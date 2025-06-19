#include "game2048.h"

void mergeTiles(int line[SIZE]) {
    int temp[SIZE] = {0};
    int final[SIZE] = {0};
    int idx = 0;
    
    // 1. Move all non-zero numbers to the left
    for (int i = 0; i < SIZE; i++) {
        if (line[i] != 0) {
            temp[idx++] = line[i];
        }
    }
    
    // 2. Merge adjacent identical numbers
    for (int i = 0; i < SIZE - 1; i++) {
        if (temp[i] != 0 && temp[i] == temp[i + 1]) {
            temp[i] *= 2;
            temp[i + 1] = 0;
        }
    }
    
    // 3. Move merged numbers to the left again
    idx = 0;
    for (int i = 0; i < SIZE; i++) {
        if (temp[i] != 0) {
            final[idx++] = temp[i];
        }
    }
    
    // 4. Copy result back to original line
    for (int i = 0; i < SIZE; i++) {
        line[i] = final[i];
    }
}
