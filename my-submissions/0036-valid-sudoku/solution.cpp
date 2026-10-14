class Solution {
public:
    bool isSafe(vector<vector<char>> &board, int row, int col, char digit) {
        // check if digit exists in col
        for(int i = 0; i < board.size(); i++) {
            if(i != row && board[i][col] == digit) {
                return false;
            }
        }

        // check if digit exists in row
        for(int j = 0; j < board.size(); j++) {
            if(j != col && board[row][j] == digit) {
                return false;
            }
        }

        // Check if digit exists in 3*3 grid 
        int stRow = (row / 3) * 3;
        int stCol = (col / 3) * 3;

        for(int i = stRow; i < stRow + 3; i++) {
            for(int j = stCol; j < stCol + 3; j++) {
                if((i != row || j != col) && board[i][j] == digit) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] != '.') {
                    if(!isSafe(board, i, j, board[i][j])) return false;
                }
            }
        }
        return true;
    }
};
