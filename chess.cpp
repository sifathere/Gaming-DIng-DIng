#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int SIZE = 8;
vector<vector<char>> board(SIZE, vector<char>(SIZE, ' '));

void initializeBoard() {
    for (int i = 0; i < SIZE; ++i) {
        board[1][i] = 'P';
        board[6][i] = 'p';
    }

    board[0][0] = board[0][7] = 'R';
    board[7][0] = board[7][7] = 'r';

    board[0][1] = board[0][6] = 'N';
    board[7][1] = board[7][6] = 'n';

    board[0][2] = board[0][5] = 'B';
    board[7][2] = board[7][5] = 'b';

    board[0][3] = 'Q';
    board[7][3] = 'q';

    board[0][4] = 'K';
    board[7][4] = 'k';
}

void printBoard() {
    for (int i = SIZE - 1; i >= 0; --i) {
        cout << i + 1 << " ";
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "  a b c d e f g h" << endl;
}

bool isValidMove(const string& move) {
    if (move.length() != 4) return false;
    char startCol = move[0];
    char startRow = move[1];
    char endCol = move[2];
    char endRow = move[3];

    return (startCol >= 'a' && startCol <= 'h' &&
            startRow >= '1' && startRow <= '8' &&
            endCol >= 'a' && endCol <= 'h' &&
            endRow >= '1' && endRow <= '8');
}

void makeMove(const string& move) {
    int startCol = move[0] - 'a';
    int startRow = move[1] - '1';
    int endCol = move[2] - 'a';
    int endRow = move[3] - '1';

    board[endRow][endCol] = board[startRow][startCol];
    board[startRow][startCol] = ' ';
}

int main() {
    initializeBoard();
    string move;
    while (true) {
        printBoard();
        cout << "Enter your move (e.g., e2e4): ";
        cin >> move;

        if (!isValidMove(move)) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        makeMove(move);
    }

    return 0;
}
