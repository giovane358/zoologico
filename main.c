#include <stdio.h>

char board[3][3]; // Tabuleiro 3x3

// Inicializa o tabuleiro com espaços em branco
void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// Mostra o tabuleiro
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
            printf("\n---|---|---\n");
    }
    printf("\n");
}

// Verifica se um jogador ganhou
char checkWinner() {
    // Linhas e colunas
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    // Diagonais
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return ' '; // Ninguém ganhou ainda
}

// Verifica se o tabuleiro está cheio
int isFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

int main() {
    int row, col;
    char currentPlayer = 'X';
    char winner = ' ';

    initializeBoard();

    while (1) {
        printBoard();
        printf("Jogador %c, informe linha e coluna (0-2 0-2): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Verifica se a jogada é válida
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Jogada inválida. Tente novamente.\n");
            continue;
        }

        board[row][col] = currentPlayer;
        winner = checkWinner();

        if (winner != ' ') {
            printBoard();
            printf("Jogador %c venceu!\n", winner);
            break;
        }

        if (isFull()) {
            printBoard();
            printf("Empate!\n");
            break;
        }

        // Alterna jogador
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
