class Solution {
public:
    pair<int, int> rec(vector<int> &nums, int i, int &ans) {
        if(i == 0) {
            ans = nums[0];    
            return {nums[0], nums[0]};
        }

        auto [prevMax, prevMin] = rec(nums, i - 1, ans);

        int currMax = max({nums[i], nums[i] * prevMax, nums[i] * prevMin});
        int currMin = min({nums[i], nums[i] * prevMax, nums[i] * prevMin});

        ans = max(currMax, ans);
        return {currMax, currMin};
    }

    int maxProduct(vector<int>& nums) {
        int ans;
        auto [mx, mn] = rec(nums, nums.size() - 1, ans);
        return ans;
    }
};
