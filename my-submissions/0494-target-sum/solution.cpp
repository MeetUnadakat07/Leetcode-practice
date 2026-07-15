class Solution {
public:
    int countSubsetSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int ele : nums) {
            totalSum += ele;
        }
        if (totalSum < abs(target)) {
            return 0;
        }
        if ((totalSum + target) % 2) {
            return 0;
        }

        int sum = (totalSum + target) / 2;

        return countSubsetSum(nums, sum);
    }
};
