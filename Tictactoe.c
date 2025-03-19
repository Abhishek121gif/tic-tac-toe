#include <stdio.h>

char board[3][3]; // Tic-Tac-Toe board
char currentPlayer = 'X'; // Start with Player 'X'

// Function to initialize the board
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the board
void printBoard() {
    printf("\n  1 2 3\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("  -+-+-\n");
    }
    printf("\n");
}

// Function to check if a player has won
int checkWin() {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return 1;
    }
    return 0;
}

// Function to check if the board is full
int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

// Function to switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to play the game
void playGame() {
    int row, col;
    while (1) {
        printBoard();
        printf("Player %c, enter row and column (1-3 1-3): ", currentPlayer);
        scanf("%d %d", &row, &col);
        
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        if (checkWin()) {
            printBoard();
            printf("🎉 Player %c wins! 🎉\n", currentPlayer);
            break;
        }
        
        if (isBoardFull()) {
            printBoard();
            printf("It's a draw! 😐\n");
            break;
        }

        switchPlayer();
    }
}

// Main function
int main() {
    initializeBoard();
    printf("🎮 Welcome to Tic-Tac-Toe! 🎮\n");
    playGame();
    return 0;
}
