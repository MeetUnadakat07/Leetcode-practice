class Solution {
public:
    int rec(int i, int j, vector<vector<int>> &dp, vector<vector<int>>& grid, int m, int n) {
        if(i == m - 1 && j == n - 1) {
            return grid[i][j];
        } 
        if(i == m || j == n) return INT_MAX;

        if(dp[i][j] != INT_MAX) return dp[i][j];

        int right = rec(i, j + 1, dp, grid, m, n);
        int down = rec(i + 1, j, dp, grid, m, n);
        dp[i][j] = min(right, down) + grid[i][j];
        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, INT_MAX));
        return rec(0, 0, dp, grid, m, n);
    }
};
