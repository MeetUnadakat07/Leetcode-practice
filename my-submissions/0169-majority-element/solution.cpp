class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxEle = INT_MIN, count = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == maxEle) {
                count++;
            } else {
                count--;
                if(count == 0) {
                    maxEle = nums[i];
                    count = 1;
                }
            }
        }
        return maxEle;
    }
};
