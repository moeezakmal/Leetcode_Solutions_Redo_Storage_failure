// Time: O(1)
// Space: O(n)


#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int* rows;
    int* cols;
    int diagonal;
    int antiDiagonal;
    int size;
} TicTacToe;


TicTacToe* ticTacToeCreate(int n) {
    TicTacToe* obj = (TicTacToe*)malloc(sizeof(TicTacToe));
    obj->rows = (int*)calloc(n, sizeof(int));
    obj->cols = (int*)calloc(n, sizeof(int));
    obj->diagonal = 0;
    obj->antiDiagonal = 0;
    obj->size = n;
    return obj;
}

int ticTacToeMove(TicTacToe* obj, int row, int col, int player) {
    int currentPlayer = (player == 1) ? 1 : -1;

    obj->rows[row] += currentPlayer;
    obj->cols[col] += currentPlayer;

    if (row == col)
        obj->diagonal += currentPlayer;

    if (col == (obj->size - row - 1))
        obj->antiDiagonal += currentPlayer;

    if (abs(obj->rows[row]) == obj->size ||
            abs(obj->cols[col]) == obj->size ||
                abs(obj->diagonal) == obj->size ||
                    abs(obj->antiDiagonal) == obj->size)
        return player;

    return 0;
}

void ticTacToeFree(TicTacToe* obj) {
    free(obj->rows); free(obj->cols);
    free(obj);
}

/**
 * Your TicTacToe struct will be instantiated and called as such:
 * TicTacToe* obj = ticTacToeCreate(n);
 * int param_1 = ticTacToeMove(obj, row, col, player);
 
 * ticTacToeFree(obj);
*/