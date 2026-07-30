class Solution {
public:
    int rec(int i, int j, vector<vector<int>> &dp, vector<vector<int>>& triangle, int n) {
        if(i == n - 1) return triangle[i][j];

        if(j > i) return 0;

        if(dp[i][j] != INT_MAX) return dp[i][j];

        int down = rec(i + 1, j, dp, triangle, n);
        int right = rec(i + 1, j + 1, dp, triangle, n);
        return dp[i][j] = min(down, right) + triangle[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
        return rec(0, 0, dp, triangle, n);
    }
};
