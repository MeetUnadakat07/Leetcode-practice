class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    int MOD = 1e9 + 7;

    bool isSafe(int i, int j, int m, int n) {
        return (i < m && j < n && i >= 0 && j >= 0);
    }

    int dfs(vector<vector<int>> &grid, int i, int j, int m, int n, vector<vector<int>> &dp) {
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // cell is also a path
        long long ans = 1;

        for(auto dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(isSafe(i_, j_, m, n) && grid[i_][j_] < grid[i][j]) {
                ans = (ans + dfs(grid, i_, j_, m, n, dp)) % MOD;
            }
        }
        return dp[i][j] = ans;
    }

    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int> (n, -1));

        int result = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                result = (result + dfs(grid, i, j, m, n, dp)) % MOD;
            }
        }
        return result;
    }
};
