// Time: O(1)
// Space: O(1)


bool winX, winO;
   
void winVH(char** board, int i) {
    if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
        if(board[i][0] == 'X')
            winX = true;
        else if(board[i][0] == 'O')
            winO = true;
    }

    if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
        if(board[0][i] == 'X')
            winX = true;
        else if(board[0][i] == 'O')
            winO = true;
    }
}

void winDiag(char** board) {
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if(board[0][0] == 'X')
            winX = true;
        else if(board[0][0] == 'O')
            winO = true;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if(board[0][2] == 'X')
            winX = true;
        else if(board[0][2] == 'O')
            winO = true;
    }
}

bool validTicTacToe(char** board, int boardSize) {
    int countX = 0, countO = 0;
    winX = false, winO = false;
    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j <boardSize; j++) {
            if(board[i][j] == 'X')
                countX++;
            else if(board[i][j] == 'O')
                countO++;
        }
    }
    if(countX < countO)
        return false;
    if(countX - countO >= 2)
        return false;
        
    for(int i = 0; i < 3; i++)
        winVH(board, i);
    winDiag(board);
    
    if(winX && winO)
        return false;
    if(winX)
        return countX - countO == 1;
    if(winO)
        return countX == countO;
    return true;
}