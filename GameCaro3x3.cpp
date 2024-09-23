#include <iostream>

using namespace std;

// Hàm để in bảng trò chơi
void printBoard(char board[3][3]) {
    cout << " Bang Tic Tac Toe: " << endl;
    cout << "   0   1   2" << endl; // tiêu đề cột
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  ---|---|---" << endl;
    }
}

// Hàm kiểm tra người chiến thắng
bool checkWin(char board[3][3], char player) {
    // Kiểm tra hàng ngang, hàng dọc và đường chéo
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char player = 'X';
    int row, col;
    int moves = 0;

    while (true) {
        printBoard(board);
        cout << "Nguoi choi " << player << ", nhap hang va cot (0-2): ";
        cin >> row >> col;

        // Kiểm tra tính hợp lệ của nước đi
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Nuoc di bi ngu, vui long nhap lai!" << endl;
            continue;
        }

        // Đánh dấu nước đi vào bảng
        board[row][col] = player;
        moves++;

        // Kiểm tra người chiến thắng
        if (checkWin(board, player)) {
            printBoard(board);
            cout << "Chuc mung nguoi choi " << player << ", ban da thang!" << endl;
            break;
        }

        // Kiểm tra xem đã có hòa chưa
        if (moves >= 9) {
            printBoard(board);
            cout << "Tro choi ket thuc, Hoa!" << endl;
            break;
        }

        // Chuyển lượt cho người chơi tiếp theo
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}