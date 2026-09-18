class Solution {
public:
    int findSum(vector<int> &nums, int goal) {

        if(goal < 0) return 0;
        int st = 0, end = 0, sum = 0, count = 0;

        // find the subarray with sum <= goal
        while(end < nums.size()) {
            sum += nums[end];
            while(sum > goal) {
                sum -= nums[st];
                st++;
            }
            count += (end - st + 1);
            end++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return findSum(nums, goal) - findSum(nums, goal - 1);
    }
};
