class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minDiff = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                int diff = abs(start - i);
                minDiff = min(minDiff, diff);
            }
        }
        return minDiff;
    }
};
