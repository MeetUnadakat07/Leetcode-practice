class Solution {
public:
    int pathSum(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j, int n) {
        if(i == n) return 0;

        if(j < 0 || j >= n) return INT_MAX;

        if(dp[i][j] != INT_MAX) {
            return dp[i][j];
        }

        int left = INT_MAX, down = INT_MAX, right = INT_MAX;

        left = pathSum(matrix, dp, i + 1, j - 1, n);
        down = pathSum(matrix, dp, i + 1, j, n);
        right = pathSum(matrix, dp, i + 1, j + 1, n);
        
        return dp[i][j] = min({left, down, right}) + matrix[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));

        int ans = INT_MAX;
        for(int j = 0; j < n; j++) {
            ans = min(ans, pathSum(matrix, dp, 0, j, n));
        }
        return ans;
    }
};
