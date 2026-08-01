class Solution {
public:
    int adv(vector<int> &nums, int l, int r, vector<vector<int>> &dp) {
        if(l == r) return nums[l];

        if(dp[l][r] != 0) return dp[l][r];

        int left = nums[l] - adv(nums, l + 1, r, dp);
        int right = nums[r] - adv(nums, l, r - 1, dp);
        return dp[l][r] = max(left, right);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        int playerAdv = adv(nums, 0, n - 1, dp);
        return playerAdv >= 0;
    }
};
