class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0], currMin = nums[0], ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int tempMax = currMax;
            currMax = max({nums[i], tempMax * nums[i], currMin * nums[i]});
            currMin = min({nums[i], tempMax * nums[i], currMin * nums[i]});
            ans = max(ans, currMax);
        }
        return ans;
    }
};
