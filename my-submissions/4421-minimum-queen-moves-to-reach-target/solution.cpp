class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int stRow = source[0], stCol = source[1];
        int endRow = target[0], endCol = target[1];
        if(stRow == endRow && stCol == endCol) return 0;
        if(stRow == endRow || stCol == endCol) return 1;
        if(abs(stRow - endRow) == abs(stCol - endCol)) return 1;
        return 2;
    }
};
