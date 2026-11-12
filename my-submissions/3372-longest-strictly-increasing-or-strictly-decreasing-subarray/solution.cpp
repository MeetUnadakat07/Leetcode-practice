class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLen = 1;
        int inc = 1, dec = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] < nums[i]) {
                inc++;
                dec = 1;
            } else if(nums[i - 1] > nums[i]) {
                dec++;
                inc = 1;
            } else {
                inc = 1;
                dec = 1;
            }
            maxLen = max({maxLen, inc, dec});
        }
        return maxLen;
    }
};
