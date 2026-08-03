class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i <= maxIdx) {
                maxIdx = max(maxIdx, i + nums[i]);
            } else {
                return false;
            }
        }
        return true;
    }
};
