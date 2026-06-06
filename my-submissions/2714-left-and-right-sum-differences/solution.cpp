class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int totalSum = 0;
        for(int ele : nums) {
            totalSum += ele;
        }

        int leftSum = 0;
        vector<int> ans(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            int rightSum = (totalSum - leftSum - nums[i]);
            ans[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }
        return ans;
    }
};
