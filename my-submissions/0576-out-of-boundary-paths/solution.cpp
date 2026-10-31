class Solution {
public:
    const int MOD = 1e9 + 7;

    long long ways(int i, int j, int m, int n, int maxMoves, vector<vector<vector<long long>>> &dp) {
        if(i >= m || j >= n || i < 0 || j < 0) return 1;
        if(maxMoves == 0) return 0;

        if(dp[i][j][maxMoves] != -1) return dp[i][j][maxMoves];

        return dp[i][j][maxMoves] =   (ways(i + 1, j, m, n, maxMoves - 1, dp) + 
                            ways(i - 1, j, m, n, maxMoves - 1, dp) +
                            ways(i, j + 1, m, n, maxMoves - 1, dp) + 
                            ways(i, j - 1, m, n, maxMoves - 1, dp)) % MOD;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<long long>>> dp (m, vector<vector<long long>> (n, vector<long long> (maxMove + 1, -1)));
        return (ways(startRow, startColumn, m, n, maxMove, dp)) % MOD;
    }
};
