class Solution {
public:
    int paths(vector<vector<int>> &grid, int i, int j, int rows, int cols, vector<vector<int>> &dp) {
        if(i >= rows || j >= cols) return 0;
        if(grid[i][j] == 1) return 0;
        if(i == rows - 1 && j == cols - 1) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        dp[i][j] = paths(grid, i + 1, j, rows, cols, dp) + paths(grid, i, j + 1, rows, cols, dp);
        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>> dp(rows, vector<int> (cols, -1));
        return paths(obstacleGrid, 0, 0, rows, cols, dp);
    }
};
