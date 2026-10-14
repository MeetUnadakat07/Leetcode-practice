class Solution {
public:
    bool isSafe(vector<vector<char>> &board, int row, int col, char digit) {
        // check if digit exists in col
        for(int i = 0; i < board.size(); i++) {
            if(board[i][col] == digit) {
                return false;
            }
        }

        // check if digit exists in row
        for(int j = 0; j < board.size(); j++) {
            if(board[row][j] == digit) {
                return false;
            }
        }

        // Check if digit exists in 3*3 grid 
        int stRow = (row / 3) * 3;
        int stCol = (col / 3) * 3;

        for(int i = stRow; i < stRow + 3; i++) {
            for(int j = stCol; j < stCol + 3; j++) {
                if(board[i][j] == digit) {
                    return false;
                }
            }
        }
        return true;
    }

    void solve(vector<vector<char>> &board, int row, int col) {
        if(row == 9) return;

        int nextRow = row, nextCol = col + 1;

        if(nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        if(board[row][col] != '.') {
            solve(board, nextRow, nextCol);
            return;
        }

        for(int digit = 1; digit <= 9; digit++) {
            char ch = digit + '0';
            if(isSafe(board, row, col, ch)) {
                board[row][col] = ch;
                solve(board, nextRow, nextCol);

                bool solved = true;
                for(int i = 0; i < 9; i++) {
                    for(int j = 0; j < 9; j++) {
                        if(board[i][j] == '.') {
                            solved = false;
                            break;
                        }
                    }
                    if(!solved) break;
                }
                if(solved) return;
                board[row][col] = '.';
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
        return;
    }
};
