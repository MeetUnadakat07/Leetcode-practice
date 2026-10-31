class Solution {
public:
    const int MOD = 1e9 + 7;
    
    long long path(vector<vector<int>>& grid, int i, int j, int rows, int cols,
             char dir, vector<vector<vector<long long>>>& dp) {
        
        // check the overflow condition
        if (i >= rows || j >= cols) {
            return 0;
        }

        // check for path complete
        if (i == rows - 1 && j == cols - 1) {
            return 1;
        }

        int d = (dir == 'L') ? 0 : 1;

        // if already calculated
        if (dp[i][j][d] != -1) {
            return dp[i][j][d];
        }

        // if it is empty cell move in both directions
        if (grid[i][j] == 0) {
            dp[i][j][d] = (path(grid, i + 1, j, rows, cols, 'D', dp) +
                          path(grid, i, j + 1, rows, cols, 'L', dp)) % MOD;
        } else {
            // if it is mirror move accordingly
            if (dir == 'L') {
                dp[i][j][d] = path(grid, i + 1, j, rows, cols, 'D', dp) % MOD;
            } else {
                dp[i][j][d] = path(grid, i, j + 1, rows, cols, 'L', dp) % MOD;
            }
        }
        return dp[i][j][d];
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<long long>>> dp(
            rows, vector<vector<long long>>(cols, vector<long long>(2, -1)));
        return path(grid, 0, 0, rows, cols, 'L', dp) % MOD;
    }
};
