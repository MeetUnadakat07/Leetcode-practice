class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int ele : nums) {
            sum += ele;
        }
        int leftSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            int currSum = sum - nums[i];
            if(leftSum * 2 == currSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};
