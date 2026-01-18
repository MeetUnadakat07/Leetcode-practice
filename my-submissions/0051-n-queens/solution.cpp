class Solution {
public:
    vector<vector<string>> result;

    bool isSafe(vector<string> &board, int row, int col) {
        int n = board.size();

        // column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            } 
        }

        return true;
    }

    void nQueens(vector<string> &board, int row) {
        int n = board.size();

        if (row == n) {
            result.push_back(board); 
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';
                nQueens(board, row + 1);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        nQueens(board, 0);
        return result;
    }
};

