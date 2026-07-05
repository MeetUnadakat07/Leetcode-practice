class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffix(n, -1);
        suffix[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = max(nums[i], suffix[i + 1]);
        }

        int maxSum = 0;
        for(int i = 0; i < n - k; i++) {
            int sum = nums[i] + suffix[i + k];
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};
